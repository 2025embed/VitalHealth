import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os
import shutil

# ===== 配置 =====
csv_path = 'tof_posture_data.csv'  # 你的 CSV 路径
output_dir = 'heatmaps'            # 输出图像文件夹

# ===== 清空输出文件夹（仅内容，保留文件夹本身）=====
if os.path.exists(output_dir):
    for item in os.listdir(output_dir):
        item_path = os.path.join(output_dir, item)
        if os.path.isfile(item_path) or os.path.islink(item_path):
            os.remove(item_path)
        elif os.path.isdir(item_path):
            shutil.rmtree(item_path)
else:
    os.makedirs(output_dir)

print(f"[INFO] 已清空输出目录：{output_dir}")

# ===== 读取 CSV =====
df = pd.read_csv(csv_path)

# ===== 遍历每一行生成热图 =====
for idx, row in df.iterrows():
    label = row['label']
    zones = row.iloc[:64].values.astype(int)
    heatmap = np.array(zones).reshape((8, 8))

    # 创建对应标签的子文件夹
    label_dir = os.path.join(output_dir, label)
    os.makedirs(label_dir, exist_ok=True)

    # 可选翻转
    heatmap = np.flipud(np.fliplr(heatmap))  # 上下+左右翻转

    # 画图
    plt.figure(figsize=(4, 4))
    plt.imshow(heatmap, cmap='hot', vmin=0, vmax=2000)
    plt.title(f'Frame {idx} - {label}')
    plt.axis('off')
    plt.colorbar()

    # 保存图像
    filename = f'frame_{idx:04d}_{label}.png'
    plt.savefig(os.path.join(label_dir, filename), bbox_inches='tight', pad_inches=0.1)
    plt.close()

print(f"[INFO] 所有热力图已保存到：{output_dir}")
