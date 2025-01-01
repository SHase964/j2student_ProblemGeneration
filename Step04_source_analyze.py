
from openai import OpenAI
from pathlib import Path
import os
from typing import Dict, Any
import json
from dotenv import load_dotenv


MODEL_NAME = "gpt-4o-2024-08-06"



class sourceAnalyzer:
    def __init__(self):
        # .envファイルから環境変数を読み込む（OPENAI_API_KEYがある必要がある）
        load_dotenv()
        self.client = OpenAI()
        self.ROLE_SETTING_PROMPT = """これより、あなたは、C言語教育と基礎プログラミングにおける優れた教育AIアシスタントとして、学習者の能力を評価します。
ソースコードからわかる学生の潜在的な能力を、常に正確に分析できる専門家です。私は教員として、あなたと協力して学習者を評価したいと考えています。"""
        self.ROLE_FEEDBACK_PROMPT = """素晴らしいです！ 分析スペシャリストとして学習者のコード理解をサポートできることを嬉しく思います。C言語の基礎概念の分析について、以下の観点から専門的な支援を提供いたします：

1. コードの構造と実行フローの詳細な分析
2. メモリ管理とデータの扱いに関する解説
3. エッジケースや潜在的な問題点の指摘
4. パフォーマンスと最適化の観点からの考察

それでは、私と一緒に、学習者のコードを分析し、理解を深めていきましょう！"""
        

    def read_problem(self, problem_file: str) -> str:
        """問題文ファイルを読み込む"""
        with open(problem_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
            return data["selected_problem"]["description"]
    
    def read_student_source(self, source_path: str) -> str:
        """ 学生のソースコードを読み込む """
        with open(source_path, 'r', encoding='utf-8') as f:
            return f.read()
    
    def create_prompt(self, problem: str, source: str) -> str:
        """ GPT-4への分析プロンプトを生成 """
        return f"""以下の情報に基づいて、学生のコードを詳細に分析し、評価を行ってください。

【問題文】
{problem}

【提出されたソースコード】
{source}

以下の観点で分析・評価を行ってください : 

1. コードの正確性と問題解決力（5点）
- 5点 : 完全に正確で、すべての要件を満たし、エッジケースも考慮
- 4点 : ほぼ正確で、主要な要件を満たす
- 3点 : 基本的な機能は動作するが、一部に問題
- 2点 : 大きな問題があり、要件を十分満たさない
- 1点 : ほとんど機能しない

2. コードの効率性（5点）
- 5点 : 最適なアルゴリズムと実装
- 4点 : 効率的な実装だが、改善の余地あり
- 3点 : 標準的な効率性
- 2点 : 非効率な実装が目立つ
- 1点 : 著しく非効率

3. コードの可読性とスタイル（5点）
- 5点 : 極めて読みやすく、整理された構造
- 4点 : 読みやすく、適切な命名と構造化
- 3点 : 基本的な可読性は確保
- 2点 : 読みにくい部分が多い
- 1点 : ほとんど読めない

4. プログラミングの基本概念の理解（5点）
- 5点 : 言語機能を適切に使いこなせている
- 4点 : 基本概念を正しく理解し適用
- 3点 : 基本的な理解は示している
- 2点 : 概念の理解が不十分
- 1点 : 基本的な概念の誤用が目立つ

各項目を5点満点で評価し、合計20点満点で点数をつけてください。

以下の形式でJSON形式で回答してください : 
{{
    "total_score": 合計点数,
    "accuracy_score": 正確性の点数,
    "efficiency_score": 効率性の点数,
    "readability_score": 可読性の点数,
    "concept_score": 基本概念の点数,
    "general_comment": "総評",
    "accuracy_comment": "正確性の評価コメント",
    "efficiency_comment": "効率性の評価コメント",
    "readability_comment": "可読性の評価コメント",
    "concept_comment": "基本概念の評価コメント",
    "improvements": ["改善点1", "改善点2", "改善点3"],
    "good_points": ["良い点1", "良い点2", "良い点3"]
}}

必ずJSON形式で回答してください。"""

    def analyze_source(self, problem: str, source: str) -> Dict[str, Any]:
        """GPT-4を使用してコードを分析し、結果をjsonで返す """
        prompt = self.create_prompt(problem, source)
        
        try:
            response = self.client.chat.completions.create(
                    model=MODEL_NAME,
                    messages=[
                        {"role": "system", "content": self.ROLE_SETTING_PROMPT},
                        {"role": "assistant", "content": self.ROLE_FEEDBACK_PROMPT},
                        {"role": "user", "content": prompt}
                    ],
                    temperature=0.2,
                    max_tokens=4000,
                    n=1,
                    response_format={"type": "json_object"}# JSON出力を強制
                )
            
            result = json.loads(response.choices[0].message.content)
            return result
        except Exception as e:
            print(f"Error in analyzing source: {e}")
            return None

    def analyze_all_submissions(self, base_problem_dir:str, problem_dirs:list[str], base_source_dirs:list[str], source_dirs:list[str]):
        """すべての提出コードを分析"""
            
        for problem_dir, base_source_dir, source_dir in zip(problem_dirs, base_source_dirs, source_dirs):
            # 学生のディレクトリを取得
            student_dirs = [d for d in os.listdir(base_source_dir) if os.path.isdir(os.path.join(base_source_dir, d))]
    
            print(problem_dir)
            
            for i, student_dir in enumerate(student_dirs):
                problem_path = os.path.join(base_problem_dir, student_dir, problem_dir)
                source_path = os.path.join(base_source_dir, student_dir)
                # ソースファイルを探索
                print(i)
                problem_file = list(Path(problem_path).glob('*_generated_promlem.json'))[0]
                source_files = list(Path(source_path).glob('*.c'))

                if source_files:
                    source_file = source_files[0]

                    # ファイル読み込み
                    problem = self.read_problem(problem_file)
                    source = self.read_student_source(str(source_file))

                    analysis = self.analyze_source(problem, source)
                    
                    if analysis:
                        result_file_path = f"./data/j24_source_analyze/{source_dir}"
                        if not os.path.exists(result_file_path):
                            os.makedirs(result_file_path)
                        with open(f"{result_file_path}/{student_dir}_source_analyze.json", 'w', encoding='utf-8') as f:
                            json.dump(analysis, f, ensure_ascii=False, indent=2)
        print("Source Analyze Successful.")

def main():
    """ソースコードに対してGPT-4oを駆使した分析"""
    analyzer = sourceAnalyzer()

    # ファイルパス設定-----------------------------------------------------
    base_source_dirs = []

    base_problem_dir = "./data/generated_problems/"
    base_source_dir = "./data/j24_source_result/"

    problem_dirs = ["02_AllPrompt_more_gpt-4o-mini-2024-07-18",
                    "04_AllPrompt_more_gemini-1.5-flash",
                    "05_AllPrompt_more_gpt-4o-2024-08-06"]

    source_dirs = ["No1_GPT4omini", "No2_gemini15Flash", "No3_GPT4o"]


    for source_dir in source_dirs:
        base_source_dirs.append(os.path.join(base_source_dir, source_dir))
    # ---------------------------------------------------------------

    analyzer.analyze_all_submissions(base_problem_dir, problem_dirs, base_source_dirs, source_dirs)

if __name__ == "__main__":
    main()