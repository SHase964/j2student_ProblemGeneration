import pandas as pd
import numpy as np
from scipy import stats
from statsmodels.stats.multicomp import pairwise_tukeyhsd
import matplotlib.pyplot as plt
from pathlib import Path
import seaborn as sns
import json
from scipy.stats import spearmanr
from statsmodels.stats.multicomp import pairwise_tukeyhsd


class CodeAnalysisCorrelation:
    def __init__(self):
        sns.set_style("whitegrid")
        # 日本語フォントの設定
        #plt.rcParams['font.family'] = 'MS Gothic'
        plt.rcParams['font.family'] = 'Hiragino Sans GB'
        plt.rcParams['font.family'] = 'Osaka'
        #plt.rcParams['font.family'] = ['Hiragino Mincho ProN', 'sans-serif']
        plt.rcParams['axes.unicode_minus'] = False
        
        # フォントサイズ設定
        plt.rcParams['font.size'] = 10          # 基本フォントサイズ
        plt.rcParams['axes.labelsize'] = 10     # 軸ラベルのフォントサイズ
        plt.rcParams['axes.titlesize'] = 12     # タイトルのフォントサイズ
        plt.rcParams['xtick.labelsize'] = 13     # x軸目盛りのフォントサイズ
        plt.rcParams['ytick.labelsize'] = 13     # y軸目盛りのフォントサイズ
        plt.rcParams['legend.fontsize'] = 10     # 凡例のフォントサイズ
        
        # 軸の設定
        plt.rcParams['axes.linewidth'] = 1.0    # 軸の太さ
        plt.rcParams['axes.grid'] = True        # グリッドの表示
        plt.rcParams['grid.linestyle'] = '--'   # グリッドのスタイル
        plt.rcParams['grid.alpha'] = 0.3        # グリッドの透明度
        
        # 図のサイズ設定
        plt.rcParams['figure.figsize'] = [6.4, 4.8]  # 論文の1カラム幅に適した比率
        plt.rcParams['figure.dpi'] = 300        # 高解像度
        
        # # マージン設定
        #plt.rcParams['figure.constrained_layout.use'] = True  # 自動レイアウト調整



    def load_form_result(self, df1, df2, df3):
        """アンケートデータの読み込みと前処理"""
        # 分析対象の列名
        columns = [df1.columns[1]] + list(df1.columns[3:9])
        # 列の短い名前のマッピング
        column_names = {
            columns[0]: 'ID',
            columns[1]: '理解しやすさ',
            columns[2]: '新しい学び',
            columns[3]: '難易度',
            columns[4]: '楽しさ',
            columns[5]: '良問評価',
            columns[6]: '時間の適切さ'
        }
        
        gpt4o_mini = df1.rename(columns=column_names)[list(column_names.values())]
        gemini = df2.rename(columns=column_names)[list(column_names.values())]
        gpt4o = df3.rename(columns=column_names)[list(column_names.values())]


        return [gpt4o_mini, gemini, gpt4o]

    def load_source_analyze(self, df1_source_path, df2_source_path, df3_source_path):
        """GPT-4の分析結果の読み込み"""
        merged_list = []
        source_analyze_dirs = [df1_source_path, df2_source_path, df3_source_path]

        for source_analyze_dir in source_analyze_dirs:
            df = pd.DataFrame(columns=["ID", "正確性", "効率性", "可読性", "基本概念"])
            source_analyze_files = list(Path(source_analyze_dir).glob('*.json'))
            for source_analyze_file in source_analyze_files:
                source_analyze_file = str(source_analyze_file)
                student_id = int(Path(source_analyze_file).stem.split('_')[0])
                
                with open(source_analyze_file, 'r', encoding='utf-8') as f:
                    data = json.load(f)
                    data_list = [data["accuracy_score"], data["efficiency_score"], data["readability_score"], data["concept_score"]]
                    
                data_list.insert(0, student_id)
                df.loc[len(df)] = data_list
            merged_list.append(df)
           
        return merged_list
    
    def load_and_merge_data(self, form_df, source_df):
        """データの読み込みとマージ"""
        # IDに基づいてデータをマージ
        merged_list = []
        for i in range(3):
            merged_list.append(pd.merge(form_df[i], source_df[i], on='ID', how='inner'))
        return merged_list
    

    def correlation_analysis(self, merged_list, model_names, form_column, source_column):
        """各モデルごとの相関分析"""
        # 分析対象の全カラム
        all_columns = form_column + source_column
        
        for df, model_name in zip(merged_list, model_names):
            # 相関係数の計算
            correlation_matrix = df[all_columns].corr(method='spearman')
            
            # ヒートマップの作成
            plt.figure(figsize=(12, 10))
            sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', center=0, fmt='.2f')
            plt.title(f'{model_name} - 評価指標間の相関係数（Spearman）')
            plt.xticks(rotation=45, ha='right')
            plt.yticks(rotation=0)
            plt.tight_layout()
            plt.savefig(f'./data/result_plot/correlations_{model_name}.png')
            plt.close()
            
            # 特に注目すべき相関（アンケート結果とソースコード評価の間）の分析
            print(f"\n=== {model_name} の重要な相関関係 ===")
            for form in form_column:
                for source in source_column:
                    corr = correlation_matrix.loc[form, source]
                    #if abs(corr) > 0.4:  # 中程度以上の相関を報告
                    print(f"{form} - {source}: {corr:.3f}")

    def performance_comparison(self, merged_list, model_names, form_column, source_column):
        """モデル間のパフォーマンス比較"""
        # アンケート結果の比較
        self._create_comparison_plot(merged_list, model_names, form_column, 
                                   'アンケート結果の比較', './data/result_plot/form_comparison.png')
        
        # ソースコード評価の比較
        self._create_comparison_plot(merged_list, model_names, source_column, 
                                   'ソースコード評価の比較', './data/result_plot/source_comparison.png')

    def _create_comparison_plot(self, merged_list, model_names, columns, title, filename):
        """比較プロットの作成"""
        means = []
        # 入れ替え
        merged_list[0], merged_list[1] = merged_list[1], merged_list[0]
        model_names[0], model_names[1] = model_names[1], model_names[0]
        for df in merged_list:
            means.append(df[columns].mean())
        
        comparison_df = pd.DataFrame(means, index=model_names, columns=columns)
        
        plt.figure(figsize=(10, 6))
        comparison_df.plot(kind='bar', ax=plt.gca())
        plt.title(title)
        plt.xticks(rotation=45, ha='right')
        plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
        plt.tight_layout()
        plt.savefig(filename)
        plt.close()

    def statistical_tests(self, merged_list, model_names, form_column, source_column):
        """統計的検定"""
        all_columns = form_column + source_column
        
        print("\n=== 統計的検定結果 ===")
        for col in all_columns:
            # Kruskal-Wallis検定
            groups = [df[col].values for df in merged_list]
            h_stat, p_val = stats.kruskal(*groups)
            
            if p_val < 0.05:
                print(f"\n{col}において有意差あり (p={p_val:.4f}):")
                # 事後検定（Mann-Whitney U検定）
                for i in range(len(model_names)):
                    for j in range(i+1, len(model_names)):
                        stat, p = stats.mannwhitneyu(
                            merged_list[i][col],
                            merged_list[j][col],
                            alternative='two-sided'
                        )
                        if p < 0.05:
                            print(f"  {model_names[i]} vs {model_names[j]}: p={p:.4f}")

    def correlation_between_metrics(self, merged_list, model_names, form_column, source_column):
        """評価指標間の相関分析"""
        for df, model_name in zip(merged_list, model_names):
            # アンケート結果の平均とソースコード評価の平均の相関
            form_mean = df[form_column].mean(axis=1)
            source_mean = df[source_column].mean(axis=1)
            
            corr, p_val = spearmanr(form_mean, source_mean)
            
            plt.figure(figsize=(8, 6))
            plt.scatter(form_mean, source_mean)
            plt.xlabel('アンケート評価平均')
            plt.ylabel('ソースコード評価平均')
            plt.title(f'{model_name}\n相関係数: {corr:.3f} (p={p_val:.4f})')
            plt.tight_layout()
            plt.savefig(f'./data/result_plot/correlation_scatter_{model_name}.png')
            plt.close()
            
            print(f"\n{model_name}の評価指標間の相関:")
            print(f"アンケート-ソースコード評価の相関係数: {corr:.3f} (p={p_val:.4f})")

    def perform_anova_tukey_analysis(self, merged_list, model_names, form_column, source_column):
        """一元配置分散分析とTukey's HSDテストの実行"""
        # 入れ替え
        merged_list[0], merged_list[1] = merged_list[1], merged_list[0]
        model_names[0], model_names[1] = model_names[1], model_names[0]
        # 分析対象の全カラム
        all_columns = form_column + source_column
        
        print("\n=== 一元配置分散分析 & Tukey's HSD 結果 ===")
        
        for column in all_columns:
            # 各モデルのデータを準備
            data_groups = []
            labels = []
            for df, model in zip(merged_list, model_names):
                values = df[column].dropna().values
                data_groups.append(values)
                labels.extend([model] * len(values))
            
            # 一元配置分散分析の実行
            f_stat, p_val = stats.f_oneway(*data_groups)
            
            print(f"\n{column}の分析結果:")
            print("-" * 50)
            print(f"F値: {f_stat:.4f}")
            print(f"p値: {p_val:.4f}")
            
            # 平均値の表示
            print("\n平均値:")
            for i, model in enumerate(model_names):
                print(f"{model}: {data_groups[i].mean():.2f}")
            
            # p値が有意水準（0.05）未満の場合、Tukey's HSDを実行
            if p_val < 0.05:
                # 全データを1次元配列に結合
                all_data = np.concatenate(data_groups)
                
                # Tukey's HSDの実行
                tukey = pairwise_tukeyhsd(all_data, labels)
                print("\nTukey's HSD 結果:")
                print(tukey)
                
                # 結果の可視化（箱ひげ図）
                plt.figure(figsize=(6, 5))
                plt.boxplot([group for group in data_groups], tick_labels=model_names)
                plt.title(f'{column}のモデル間比較') 
                plt.savefig(f'./data/result_plot/boxplot_{column}.png')
                plt.close()
            
            print("\n" + "=" * 50)

    def generate_summary_statistics(self, merged_list, model_names, form_column, source_column):
        """要約統計量の生成"""
        print("\n=== 要約統計量 ===")
        for df, model_name in zip(merged_list, model_names):
            print(f"\n{model_name}:")
            print("\nアンケート結果:")
            print(df[form_column].describe())
            print("\nソースコード評価:")
            print(df[source_column].describe())


    def run_analysis(self, df1, df2, df3, df1_source_path, df2_source_path, df3_source_path,analysis_dir):
        """分析の実行"""
        # データの読み込み
        llm_form = self.load_form_result(df1, df2, df3)
        llm_source = self.load_source_analyze(df1_source_path, df2_source_path, df3_source_path)
        merged_list = self.load_and_merge_data(llm_form, llm_source)

        # 各種要素
        form_column = list(llm_form[0].columns)
        form_column.remove('ID')
        source_column = list(llm_source[0].columns)
        source_column.remove('ID')

        print(form_column)

        # モデルの名前
        model_names = ["GPT-4o-mini", "Gemini-1.5-Flush", "GPT-4o"]

        print(merged_list[0].columns)

       
        print("1. 相関分析の実行...")
        self.correlation_analysis(merged_list, model_names, form_column, source_column)
        
        print("\n2. モデル間比較の実行...")
        self.performance_comparison(merged_list, model_names, form_column, source_column)
        
        print("\n3. 統計的検定の実行...")
        self.statistical_tests(merged_list, model_names, form_column, source_column)
        
        print("\n4. 評価指標間の相関分析...")
        self.correlation_between_metrics(merged_list, model_names, form_column, source_column)

        print("\n5. 一元配置分散分析とTukey's HSDの実行...")
        self.perform_anova_tukey_analysis(merged_list, model_names, form_column, source_column)
    
        print("\n5. 要約統計量の生成...")
        self.generate_summary_statistics(merged_list, model_names, form_column, source_column)


def perform_anova_analysis(df1, df2, df3):
    """
    3つのグループに対して一元配置分散分析とTukey's HSDを実行
    
    Parameters:
    df1, df2, df3: それぞれのモデルのデータを含むDataFrame
    """
    # 分析対象の列名
    columns = list(df1.columns[3:9])
    
    # 列の短い名前のマッピング
    column_names = {
        columns[0]: '理解しやすさ',
        columns[1]: '新しい学び',
        columns[2]: '難易度',
        columns[3]: '楽しさ',
        columns[4]: '良問評価',
        columns[5]: '時間の適切さ'
    }
    
    results = {}
    results = {}
    
    for col in columns:
        # 各グループのデータを取得
        gpt4o_mini = df1[col].dropna()
        gemini = df2[col].dropna()
        gpt4o = df3[col].dropna()
        
        # ANOVAの実行
        f_statistic, p_value = stats.f_oneway(gpt4o_mini, gemini, gpt4o)
        
        # データをTukey's HSD用に準備
        all_data = np.concatenate([gpt4o_mini, gemini, gpt4o])
        group_labels = np.concatenate([
            ['GPT4o_mini'] * len(gpt4o_mini),
            ['Gemini_1.5_Flush'] * len(gemini),
            ['GPT4o'] * len(gpt4o)
        ])
        
        # Tukey's HSDの実行
        tukey = pairwise_tukeyhsd(all_data, group_labels)
        
        # 結果の保存
        results[column_names[col]] = {
            'f_statistic': f_statistic,
            'p_value': p_value,
            'tukey_results': tukey,
            'means': {
                'GPT4o_mini': np.mean(gpt4o_mini),
                'Gemini_1.5_Flush': np.mean(gemini),
                'GPT4o': np.mean(gpt4o)
            }
        }
    
    return results

def print_analysis_results(results):
    """
    分析結果を見やすく出力
    """
    print("=== 一元配置分散分析 & Tukey's HSD 結果 ===\n")
    
    for metric, result in results.items():
        print(f"\n{metric}の分析結果:")
        print("-" * 50)
        print(f"F値: {result['f_statistic']:.4f}")
        print(f"p値: {result['p_value']:.4f}")
        print("\n平均値:")
        for model, mean in result['means'].items():
            print(f"{model}: {mean:.2f}")
        
        print("\nTukey's HSD 結果:")
        print(result['tukey_results'])
        print("\n" + "=" * 50)

def form_analyze():
    """フォームの回答結果を使用した分析"""
    # CSVファイルを読み込む
    df1_form = pd.read_csv('./data/j24_form_result/No1_GPT4omini.csv')
    df2_form = pd.read_csv('./data/j24_form_result/No2_gemini15Flash.csv')
    df3_form = pd.read_csv('./data/j24_form_result/No3_GPT4o.csv')

    # 分析を実行
    results = perform_anova_analysis(df1_form, df2_form, df3_form)

    # 結果を表示
    print_analysis_results(results)



def form_source_analyze():
    """フォームの回答結果とGPT-4Oが算出した回答結果の両方を合わせた分析"""

    analyzer = CodeAnalysisCorrelation()
   
    # CSVファイルを読み込む
    df1_form = pd.read_csv('./data/j24_form_result/No1_GPT4omini.csv')
    df2_form = pd.read_csv('./data/j24_form_result/No2_gemini15Flash.csv')
    df3_form = pd.read_csv('./data/j24_form_result/No3_GPT4o.csv')

    df1_source_path = './data/j24_source_analyze/No1_GPT4omini'
    df2_source_path = './data/j24_source_analyze/No2_gemini15Flash'
    df3_source_path = './data/j24_source_analyze/No3_GPT4o'

    analysis_dir = './data/form_source_analysis'
    
    # 分析の実行
    analyzer.run_analysis(
        df1_form, df2_form, df3_form, 
        df1_source_path, df2_source_path, df3_source_path,
        analysis_dir
    )
    

def main():
    form_analyze()
    #form_source_analyze()

if __name__ == "__main__":
    main()