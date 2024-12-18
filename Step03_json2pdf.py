import json
import markdown
import pdfkit
import os
from PyPDF2 import PdfMerger, PdfReader, PdfWriter

# パラメータ(実行する時変える)----------------------------------------
DATES = [ # pdfのタイトル
        "2024-12-13(金)", 
        #"2024-12-18(水)", 
        #"2024-12-20(金)"
    ]
MODEL_FILES = [ #生成した問題のjsonファイルのフォルダ名
        "02_AllPrompt_more_gpt-4o-mini-2024-07-18", 
        #"04_AllPrompt_more_gemini-1.5-flash", 
        #"05_AllPrompt_more_gpt-4o-2024-08-06"
]

MODEL_FILE_IDS = [ 
        "02", 
        #"04", 
        #"05"
]
# ---------------------------------------------------------------



def create_blank_pdf(output_path):
    """空白のPDFページを作成する"""
    blank_html = """
    <html>
        <head>
            <style>
                body { margin: 0; padding: 0; }
                @page { margin: 0; }
            </style>
        </head>
        <body></body>
    </html>
    """
    
    config = pdfkit.configuration(wkhtmltopdf='/usr/local/bin/wkhtmltopdf')
    options = {
        'page-size': 'A4',
        'margin-top': '0',
        'margin-right': '0',
        'margin-bottom': '0',
        'margin-left': '0'
    }
    
    pdfkit.from_string(blank_html, output_path, configuration=config, options=options)

def ensure_even_pages(pdf_path):
    """PDFのページ数が偶数になるように調整する"""
    reader = PdfReader(pdf_path)
    writer = PdfWriter()
    
    # 既存のページをコピー
    for page in reader.pages:
        writer.add_page(page)
    
    # ページ数が奇数の場合、空白ページを追加
    if len(reader.pages) % 2 != 0:
        # 一時的な空白ページを作成
        temp_dir = os.path.dirname(pdf_path)
        blank_path = os.path.join(temp_dir, "temp_blank.pdf")
        create_blank_pdf(blank_path)
        
        # 空白ページを追加
        blank_reader = PdfReader(blank_path)
        writer.add_page(blank_reader.pages[0])
        
        # 更新したPDFを保存
        with open(pdf_path, 'wb') as output_file:
            writer.write(output_file)
        
        # 一時ファイルを削除
        os.remove(blank_path)


def create_markdown_content(problem_data, number, date, student_id):
    """JSONデータからマークダウン形式のコンテンツを生成する"""
    problem_data = problem_data["selected_problem"]
    student_id_html = f'<div style="text-align: right; font-size: 1.0em;">学生ID：{student_id}</div>' if student_id else ''
   
    markdown_content = f"""
{student_id_html}

##{date} プログラミング基礎II, 演習IB
# 学力テスト from LLM No.{number}

## 問題の説明
{problem_data['description']}


## 入出力例

### 例

<h4 style="color: #2c3e50;">入力</h4>

```
{problem_data['examples'][0]['input'].strip()}```

<h4 style="color: #2c3e50;">出力</h4>

```
{problem_data['examples'][0]['output'].strip()}```
"""

    # learning_objectivesが存在する場合のみ、学習目標セクションを追加
    if 'learning_objectives' in problem_data and problem_data['learning_objectives']:
        markdown_content += """
## 学習目標
"""
        for objective in problem_data['learning_objectives']:
            markdown_content += f"- {objective}\n"
    
    return markdown_content

def json_to_pdf(json_file_path, pdf_path, number, date, student_id):
    """JSONファイルを読み込み、PDFファイルを生成する"""

    # ディレクトリ作成
    directory = os.path.dirname(pdf_path)
    if directory and not os.path.exists(directory):
        os.makedirs(directory)

    # JSONファイルを読み込む
    with open(json_file_path, 'r', encoding='utf-8') as file:
        problem_data = json.load(file)
    
    # マークダウンコンテンツを生成
    markdown_content = create_markdown_content(problem_data, number, date, student_id)
    
    # マークダウンをHTMLに変換
    html_content = markdown.markdown(markdown_content)
    
    # HTMLにスタイルを適用
    styled_html = f"""
    <html>
        <head>
            <style>
                body {{ 
                    font-family: "Helvetica", "Arial", "Hiragino Sans",sans-serif; 
                    margin: 2em; 
                    font-size: 12pt;
                    line-height: 1.6;
                }}
                h1 {{
                    color: #2c3e50;
                    font-size: 20pt;
                    text-align: center;
                    margin-top: 1em;
                    margin-bottom: 1em;
                }}
                h2 {{
                    color: #2c3e50;
                    font-size: 18pt;
                    margin-top: 1.5em;
                    border-bottom: 2px solid #34495e;
                    padding-bottom: 0.2em;
                }}
                h3 {{
                    color: #2c3e50;
                    font-size: 16pt;
                }}
                h4 {{
                    color: #27ae60;
                    font-size: 12pt;
                }}
                code {{
                    background-color: #f8f9fa;
                    padding: 0.2em 0.4em;
                    font-size: 14pt;
                    white-space: pre;
                }}
                pre {{
                    background-color: #f8f9fa;
                    padding: 1em;
                    border-radius: 4px;
                    font-size: 14pt;
                    white-space: pre;
                    overflow-x: auto;
                }}
                ul {{
                    font-size: 12pt;
                    margin-left: 1em;
                }}
                li {{
                    margin-bottom: 0.5em;
                }}
            </style>
        </head>
        <body>
            {html_content}
        </body>
    </html>
    """
    # wkhtmltopdfのパスを設定
    config = pdfkit.configuration(wkhtmltopdf='/usr/local/bin/wkhtmltopdf')
    
    # オプションを設定（日本語フォントのサポートを含む）
    options = {
        'encoding': 'UTF-8',
        'enable-local-file-access': None
    }
    # HTMLをPDFに変換
    pdfkit.from_string(styled_html, pdf_path, configuration=config, options=options)
    
    ensure_even_pages(pdf_path)


def merge_pdfs(pdf_files, concat_pdf_path):
    """複数のPDFファイルを1つに結合する"""
    merger = PdfMerger()
    
    try:
        # 各PDFファイルを結合
        for pdf_file in pdf_files:
            merger.append(pdf_file)
        
        # 結合したPDFを保存
        merger.write(concat_pdf_path)
        print(f"PDFの結合が完了しました: {concat_pdf_path}")
        
    except Exception as e:
        print(f"PDFの結合中にエラーが発生しました: {str(e)}")
    
    finally:
        merger.close()

# 使用例
if __name__ == "__main__":

    pdf_files = []
    
    for i, (date,model_file_id, model_file) in enumerate(zip(DATES,MODEL_FILE_IDS,MODEL_FILES)):
        print(model_file)
        for id in range(1,42):
            json_file = f"./data/generated_problems/{id}/{model_file}/{model_file_id}_generated_promlem.json"
            pdf_file = f"./data/generated_problems_pdf/{model_file}/{id}_{model_file_id}_generated_promlem.pdf"
            concat_pdf_file = f"./data/generated_problems_pdf/{model_file}_generated_promlem.pdf"
            json_to_pdf(json_file_path=json_file, 
                        pdf_path=pdf_file,
                        number=i+1,
                        date=date,
                        student_id=id
            )
            pdf_files.append(pdf_file)
        merge_pdfs(pdf_files,concat_pdf_path=concat_pdf_file)
        pdf_files = []
