import os

# 元のディレクトリ名 (j23401からj23440)
original_dirs = [f"j234{str(i).zfill(2)}" for i in range(1, 41)]

# 新しいディレクトリ名
new_names = [
    12, 18, 5, 24, 19, 1, 27, 33, 6, 34, 2, 37, 20, 13, 10, 25, 3, 32, 38, 4,
    26, 9, 15, 16, 21, 31, 22, 17, 23, 39, 7, 35, 40, 8, 36, 28, 29, 11, 30, 14, 41
]

# ディレクトリ名を変更
for old_name, new_name in zip(original_dirs, new_names):
    if os.path.exists(old_name):
        os.rename(old_name, str(new_name))
        print(f"mv {old_name} {new_name}")
    else:
        print(f"Warning: {old_name} does not exist")

