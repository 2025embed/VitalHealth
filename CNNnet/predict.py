import torch
import numpy as np
import serial
import re
from train.train import TOFPostureCNN  # 这里假设你的模型类定义在 model.py 里
from sklearn.preprocessing import LabelEncoder

# ====== 配置 ======
SERIAL_PORT = 'COM13'
BAUD_RATE = 115200
MODEL_PATH = 'train/posture_cnn_model.pth'  # 你的模型路径
LABELS = ['backward', 'forward', 'left_lean', 'right_lean', 'upright']  # 按训练时的顺序改！

# ====== 加载模型 ======
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

model = TOFPostureCNN(num_classes=len(LABELS))
model.load_state_dict(torch.load(MODEL_PATH, map_location=device))
model.eval().to(device)

# ====== 标签编码器（为了反解预测结果）======
label_encoder = LabelEncoder()
label_encoder.fit(LABELS)

# ====== 打开串口 ======
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
print(f"[INFO] Serial port {SERIAL_PORT} opened.")

# ====== 正则表达式匹配每一行 ======
zone_pattern = re.compile(r"Zone(\d+)_Status(\d+)_Distance(\d+);")

def collect_one_frame():
    """收集完整的 64 个点的数据"""
    distances = [None] * 64
    filled = 0

    while filled < 64:
        line = ser.readline().decode('utf-8', errors='ignore').strip()
        if not line:
            continue

        match = zone_pattern.match(line)
        if match:
            zone_idx = int(match.group(1))
            if(match.group(2) == '005'):
                distance = int(match.group(3))
            else:
                distance = 2000
            if 0 <= zone_idx < 64:
                if distances[zone_idx] is None:
                    distances[zone_idx] = distance
                    filled += 1
    return distances

def predict(frame_data):
    """输入一帧64点，推理输出类别"""
    # 转成 8x8 热图
    heatmap = np.array(frame_data).astype(np.float32).reshape(8,8)
    # 可选翻转
    # heatmap = np.flipud(np.fliplr(heatmap))
    # 变成Tensor，形状 [1, 1, 8, 8]
    input_tensor = torch.tensor(heatmap).unsqueeze(0).unsqueeze(0).to(device)

    with torch.no_grad():
        outputs = model(input_tensor)
        pred_idx = outputs.argmax(dim=1).item()
        pred_label = label_encoder.inverse_transform([pred_idx])[0]

    return pred_label

# ====== 主循环 ======
try:
    while True:
        print("[INFO] Collecting a new frame...")
        frame = collect_one_frame()
        result = predict(frame)
        print(f"[PREDICT] 当前推理结果：{result}")

except KeyboardInterrupt:
    print("\n[INFO] 退出程序.")
finally:
    ser.close()
