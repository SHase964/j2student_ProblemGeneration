import pandas as pd
from pathlib import Path
import os

ROOT_PATH = "."

def create_dataframe(source_file_path, index, prombem_index):
    user_ids = sorted([d.name for d in Path(source_file_path).iterdir() if d.is_dir()],
                     key=lambda x: int(x)) # 昇順に並べ替え(int型に変換可能な時)
    data_dict = {}

    for user_id in user_ids:
        contents = []
        #for dir_name, file_name in index:
        for file_name in prombem_index:
            #source_file_path = os.path.join(file_path, user_id, dir_name, file_name)
            file_path = os.path.join(source_file_path, user_id, file_name)
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
            except Exception as e:
                content = ""  # ファイルが存在しない場合は""
            contents.append(content)

        # user_idをキーとしてコンテンツのリストを格納
        data_dict[user_id] = contents

    source_df = pd.DataFrame(data_dict, index=index)
    return source_df

source_file_path = f"{ROOT_PATH}/data/j24_source_kouki/"
problem_df = pd.read_csv(f"{ROOT_PATH}/data/j24_problems_kouki.csv")

multi_index = [problem_df["date"].values.tolist(),problem_df["problem_id"].values.tolist()]
multi_index = list(zip(*multi_index))
multi_index = pd.MultiIndex.from_tuples(multi_index, names=['date', 'problem_id'])

prombem_index = problem_df["problem_id"].values.tolist()

# ソースコードのcsv作成
source_df = create_dataframe(source_file_path, multi_index, prombem_index)

# 保存
source_df.T.to_csv(f"{ROOT_PATH}/data/j24_source_kouki.csv")
