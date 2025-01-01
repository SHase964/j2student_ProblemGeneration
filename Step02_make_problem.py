from typing import List, Dict
import time
from dataclasses import dataclass
import pandas as pd 
from openai import OpenAI
from dotenv import load_dotenv
import json
import google.generativeai as genai
import os


# パラメータ(実行する時変える)----------------------------------------
ROOT_PATH = "."
# MODEL_NAME = "gpt-4o-mini-2024-07-18"
#MODEL_NAME = "gpt-4o-2024-08-06"
#MODEL_NAME = "gemini-1.5-flash"
MODEL_NAME = "gemini-1.5-pro"
STEP="06"
PROMPT_STEP_NAME = f"{STEP}_AllPrompt_more_{MODEL_NAME}" 
# ---------------------------------------------------------------

@dataclass
class LearnerSubmission:
    problem_id: str        # 問題id 
    problem_statement: str # 問題文
    code: str              # 学生の回答
    model_code: str            # 模範回答    

@dataclass
class LearnerProfile:
    learner_id: str # ユーザid
    submissions: List[LearnerSubmission] # 提出した問題のリスト

class PromptEngineeringSystem:
    def __init__(self):
    # Role Prompting
    ## Role-Setting Prompt ： 教師としての役割を明記
    ## Role-FeedBack Prompt：それに対する応答を作成。LLMに教師としての役割を再認識させる
        load_dotenv()  # .envファイルの読み込み
        if "gpt" in MODEL_NAME: 
            self.client = OpenAI()
        
        if "gemini" in MODEL_NAME:
            genai.configure(api_key=os.environ["GEMINI_API_KEY"])
            
            self.client = genai.GenerativeModel(
                model_name=MODEL_NAME,
            )
        self.ROLE_SETTING_PROMPT = """これより、あなたは、C言語教育と基礎プログラミングにおける優れた教育AIアシスタントとして、学習者の成長をサポートします。
ポインタ、配列、文字列操作といったC言語の基礎概念について、常に正確な問題設計とコード分析を提供できる専門家です。私は教員として、あなたと協力して学習者の成長を支援したいと考えています。"""
        self.ROLE_FEEDBACK_PROMPT = """素晴らしいです！ 教育AIアシスタントとして学習者の成長をサポートできることを嬉しく思います。C言語の基礎概念の指導と問題設計について、以下の観点から専門的な支援を提供いたします：

1. 学習者の理解度に応じた最適な問題設計と詳細なコード分析
2. プログラミング概念の段階的な理解を促す指導方針の提案
3. 実践的で興味を引き出す課題の設計
4. コード改善につながる具体的なフィードバック方法の提示

それでは、私と一緒に、学習者の状況を分析し、最適な問題設計を行っていきましょう！
"""

    # Few-Shot
    ## 分析から問題生成まで一貫した例を２つ用意
        self.FEW_SHOT_EXAMPLES = """
# 例1: 初級者向け問題生成
Input: {
    "recent_submission": {
        "problem_statement": "「Hello World」という文字列を標準出力に表示するプログラムを作成してください。プログラムは適切なヘッダファイルをインクルードし、main関数から0を返すようにしてください。", 
        "code": "include <stdio.h>\n\nvoid main() {\n    printf('Hello World');\n}"
        }
}
Analysis: 
- #includeの#記号の欠落
- シングルクォートの誤用（文字列にはダブルクォートが必要）
- main関数の戻り値型をvoidで宣言
- 戻り値のreturn文が欠如
- セミコロンの欠落
Generated Problem: {
    "difficulty": 2,
    "description": "二つの整数を変数に代入し、その和を計算して表示するプログラムを作成してください。",
    "learning_objectives": ["#includeディレクティブの正しい記述", "main関数の適切な定義", "printf関数での文字列リテラルの使用", "セミコロンによる文の区切り"],
}

# 例2: 中級者向け問題生成
Input: {
    "recent_submission": {
        "problem_statement": "整数の配列とその要素数を引数として受け取り、配列内の全要素の合計値を計算して返す関数sum()を実装してください。", 
        "code": "#include <stdio.h>\n\nint sum(int arr[], int size) {\n    int total = 0;\n    for(int i=0; i<size; i++) {\n        total += arr[i];\n    }\n    return total;\n}"
    }
}
Analysis:
- 配列の基本操作を理解
- 関数の引数としての配列渡しを理解
- forループによる反復処理を実装可能
Generated Problem: {
    "difficulty": 5,
    "description": "文字列を受け取り、その文字列内の数字文字の数をカウントする関数を実装してください。ポインタ演算を使用して文字列を走査してください。",
    "learning_objectives": ["文字列処理用ヘッダの使用", "ポインタ演算", "文字列操作", "文字種の判定"],
}"""

    def generate_problem(self, learner: LearnerProfile) :
        """Chain-of-ThoughtとTask分解を使用して問題を生成"""

        # base_prompt: 問題生成時のプロンプトを作成
        base_prompt = self._create_base_prompt(learner)
        
        # Self-Consistency: 複数の問題候補を生成
        candidates = []

        # 候補として3つの出力を出す
        for _ in range(3):
            response = self._call_llm_api(base_prompt, temperature=0.7)
            candidates.append(json.loads(response))

        # 問題候補の相互検証
        verification_result = self._verify_problems(candidates)
  
        final_problem = verification_result

        return final_problem, candidates

    def _create_base_prompt(self, learner: LearnerProfile) -> str:
        """基本プロンプトの生成（Chain-of-Thought）"""
        learner_info = self._format_learner_info(learner)
        
        return f"""
それではこれからあなたには、学習者の過去の問題解答を分析し、その理解度と潜在能力に基づいて、過去の問題とは異なる文脈での最適な難易度の問題を生成してもらいます。
学習者は最大で3問の問題に解答しており、解けなかった問題は未解答となっています。複数の問題に対する学生の解答を包括的に分析して、使用したスキルセットを網羅的に評価した上で問題を生成させてください。
また、学習者の習熟度に応じて、基礎が身についている学習者には応用的な課題を、基礎の強化が必要な学習者には適切な基礎問題を提供してください。

# 現在の学習者が解いた問題と、私が作成した模範回答
{learner_info}

# 思考プロセス
以下のステップで問題を生成してください：

1. 学習者分析
- 現在の理解度の評価
- 使用しているプログラミングパターンの分析
- 学習の進捗速度の評価

2. 難易度決定
- 適切な難易度上昇の程度
- 導入する新概念の数
- 既存知識の活用方法

3. 問題設計
- 具体的な問題シナリオ
- 実装要件
- 評価基準

以上の分析に基づいて、以下のJSON形式で問題を生成してください：

{{
    "problem_id": "一意のID",
    "difficulty": "1-10の難易度",
    "description": "新たな問題文",
    "reason": "この問題を作成した分析結果の詳細"
    "examples": [
        {{
            "input": "入力例",
            "output": "出力例",
            "explanation": "説明"
        }}
    ],
    "learning_objectives": ["学習目標のリスト"]

# 作文例
{self.FEW_SHOT_EXAMPLES}
}}"""

    def _verify_problems(self, candidates: List[Dict]) -> Dict:
        """問題候補の検証（Self-Consistency）"""
        verification_prompt = f"""
学習者の能力の分析結果より、3つ問題候補を考案しました。
問題候補から、最も適切な問題を選択してください。

問題候補：
{json.dumps(candidates, ensure_ascii=False, indent=2)}

評価基準：
1. 学習者の分析結果との適合性
2. 学習目標の明確さ
3. 問題の一貫性
4. 実装可能性

選択理由と改善点を含めて以下のJSON形式で回答してください。
{{
    "selected_problem": {{
        "problem_id": "一意のID",
        "difficulty": "1-10の難易度",
        "description": "新たな問題文",
        "reason": "この問題を作成した分析結果の詳細"
        "examples": [
            {{
                "input": "入力例",
                "output": "出力例",
                "explanation": "説明"
            }}
        ],
        "learning_objectives": ["学習目標のリスト"]
    }},
    "reasoning": "選択理由",
    "improvements": ["改善点のリスト"]
}}"""

        verification_result = self._call_llm_api(verification_prompt, temperature=0.2)
        return json.loads(verification_result)

    def _format_learner_info(self, learner: LearnerProfile) -> str:
        """学習者情報のフォーマット"""
        recent_submissions = [
            {
                "problem_id": s.problem_id,
                "problem_statement": s.problem_statement,
                "code": s.code,
                "model answer":s.model_code
            }
            for s in learner.submissions  # 学生が解いた問題全て
        ]
        
        return json.dumps({
            "learner_id": learner.learner_id,
            "recent_submissions": recent_submissions
        }, ensure_ascii=False, indent=2)

    def _call_llm_api(self, prompt: str, temperature: float) -> str:
        """GPT-4 APIの呼び出し"""
        try:
            # for gpt
            if "gpt" in MODEL_NAME:
                response = self.client.chat.completions.create(
                    model = MODEL_NAME,  # または "gpt-4" など、利用可能なGPT-4モデル
                    messages=[
                        {"role": "system", "content": self.ROLE_SETTING_PROMPT},
                        {"role": "assistant", "content": self.ROLE_FEEDBACK_PROMPT},
                        {"role": "user", "content": prompt}
                    ],
                    temperature=temperature,
                    max_tokens=4000,
                    n=1,
                    response_format={"type": "json_object"}# JSON出力を強制
                )
                return response.choices[0].message.content
            # for gemini
            if "gemini" in MODEL_NAME:
                time.sleep(30)
                generation_config = {
                    "temperature": temperature,
                    "max_output_tokens": 4000,
                    "response_mime_type": "application/json",
                }
                self.client._generation_config = generation_config
                message = self.ROLE_SETTING_PROMPT +"\n\n"+ self.ROLE_FEEDBACK_PROMPT + "\n\n"+ prompt
                response = self.client.generate_content(message)
                return response.text
            
        except Exception as e:
            print(f"API呼び出しエラー: {str(e)}")
            raise RuntimeError(f"Failed to generate problem: {str(e)}") from e

# 使用例
def main():
    # データ読み込み-----------------------------------------------
    problem_df = pd.read_csv(f"{ROOT_PATH}/data/j24_problems_kouki.csv")
    model_code_df = pd.read_csv(f"{ROOT_PATH}/data/j24_source_kouki_model_code.csv")
    source_df = pd.read_csv(f"{ROOT_PATH}/data/j24_source_kouki.csv",header=[0, 1],index_col=0) # こちらの転置の方を使用
    source_df = source_df.fillna("")

    df_columns = source_df.columns # 日付と問題
    df_indices = source_df.index   # 学生ID

    problem_list = [] # 問題のリスト
    model_code_list = [] # 模範回答のリスト
    source_list = []  # ソースコードのリスト

    # システムの初期化-----------------------------------------------
    system = PromptEngineeringSystem()

    # 問題文のリスト作成-----------------------------------------------
    for df_column in df_columns:
        problem_txt = problem_df[
            (problem_df['date'] == df_column[0]) &
            (problem_df['problem_id'] == df_column[1])
        ]['problem_text'].values[0]

        problem_list.append(problem_txt)

    problem_ids = df_columns.get_level_values(1).tolist() # 問題のID（No4~No6）だけを取得

    # 模範回答作成-----------------------------------------------
    for df_column in df_columns:
        source_model_code = model_code_df[
            (model_code_df['date'] == df_column[0]) &
            (model_code_df['problem_id'] == df_column[1])
        ]['model_code'].values[0]

        model_code_list.append(source_model_code)


    # 生成開始-----------------------------------------------
    for df_index in df_indices:
        print(df_column)
        for df_column in df_columns:
            valid_source = source_df.at[df_index, (df_column[0], df_column[1])] # 評価対象のソースコード
            if not valid_source:
                valid_source = "未回答" # ソースコードがない場合は未回答とする
            
            source_list.append(valid_source)

        if not all(x == "未回答" for x in source_list) :  # 全ての問題で未回答じゃない場合
            # ユーザを定義
            learner = LearnerProfile(
                learner_id=df_index,
                submissions=[
                    LearnerSubmission(
                        problem_id=problem_id,
                        problem_statement=problem_txt,
                        code=source,
                        model_code=model_code
                    ) 
                    for problem_id, problem_txt, source, model_code 
                        in zip(problem_ids, problem_list, source_list, model_code_list)
                ]
            )
            generated_problem, candidated_problems = system.generate_problem(learner)

            result_file_path = f"{ROOT_PATH}/data/generated_problems/{df_index}/{PROMPT_STEP_NAME}"
            os.makedirs(result_file_path, exist_ok=True)
            with open(f"{result_file_path}/{STEP}_generated_promlem.json", 'w', encoding='utf-8') as f:
                json.dump(generated_problem, f, ensure_ascii=False, indent=2)
            
            for i, candidated_problem in enumerate(candidated_problems):
                with open(f"{result_file_path}/{STEP}_candidated_promlem_{i}.json", 'w', encoding='utf-8') as f:
                   json.dump(candidated_problem, f, ensure_ascii=False, indent=2)
            time.sleep(30)

        source_list = []


if __name__ == "__main__":
    main()
