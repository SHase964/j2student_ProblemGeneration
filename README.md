# 学習者のスキルを考慮したソースコード問題の生成
## Step1: ソースコード抽出、問題文抽出
### ソースコードの抽出(Step01_source_extraction.py)
./data/j24_source_kouki/内のソースコードをcsvに出力
- ./data/j24_source_kouki/の階層（数字は学生ID）
```
./data/j24_source_kouki
├── 1
│   ├── No1.c~
│   ├── No4.c
│   ├── No5.c
│   ├── No5.c~
│   ├── a.out
│   ├── execNo4
│   ├── execNo5
│   ├── execNo6
│   ├── execNo7
│   └── sample7.c
├── 10
│   ├── No4.c
│   ├── No4.c~
│   ├── No5.c
│   ├── No5.c~
│   ├── No6.c
│   └── a.out
├── 11
...

```
- 出力：./data/j24_source_kouki.csv

### 問題文の抽出(Step01_problem_extraction.py)
./data/j24_problem_zenki/内の問題ファイルをcsvに出力
- 問題はほぼdocs形式
- exam問題はcsvに手打ちする必要がある(koukiは手打ちで全部やりました)
- 出力：./data/j24_problem_kouki.csv

## Step2: LLMによる問題作成
問題文と学生のソースコードと、大枝先生による模範回答を照らし合わせて、その学生に最適な問題を作成する。
- 実装モデル(使用する時は.envにAPIキーを記入)
    - gpt-4o-mini-2024-07-18
    - gpt-4o-2024-08-06
    - gemini-1.5-flash
    - gemini-1.5-pro
- 使用プロンプト手法（：使用意図）
    - Role Play Prompting：LLMに役割を明記
    - Few-Shot：生成する問題の形式を定義
    - Chain-of-Through(CoT)：学生のスキル分析
    - Self-Consistency：複数の問題候補を出力させ、最もいいものを選定
- 出力：./data/generated_problems/
    - 学生ごと、モデルごとにファイルを構成
    - Self-Consistencyで生成させた問題候補（3つ）と、最終的に選定した問題がjson形式で保存されている
```
./data/generated_problems
├── 1
│   ├── 01_AllPrompt_gpt-4o-mini-2024-07-18
│   │   ├── 01_candidated_promlem_0.json
│   │   ├── 01_candidated_promlem_1.json
│   │   ├── 01_candidated_promlem_2.json
│   │   └── 01_generated_promlem.json
│   ├── 02_AllPrompt_more_gpt-4o-mini-2024-07-18
│   │   ├── 02_candidated_promlem_0.json
│   │   ├── 02_candidated_promlem_1.json
│   │   ├── 02_candidated_promlem_2.json
│   │   └── 02_generated_promlem.json
│   ├── 03_Non_RolePrompt_gpt-4o-mini-2024-07-18
│   │   ├── 03_candidated_promlem_0.json
│   │   ├── 03_candidated_promlem_1.json
│...
```

## Step3: 問題文をpdf化
生成した問題をpdf化し、学生に配布。実際に解いてもらって、評価をしてもらう。
- 一人ひとりのpdfを作成 → pdf結合して1回で印刷できるように
- 出力：./data/generated_problems_pdf