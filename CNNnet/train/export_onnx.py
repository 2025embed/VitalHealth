import torch
import torch.onnx
from train import TOFPostureCNN  # 替换成你的模型定义

# 加载模型
model = TOFPostureCNN(5)
model.load_state_dict(torch.load('posture_cnn_model.pth'))
model.eval()

# 假输入
dummy_input = torch.randn(1, 1, 8, 8)

# 导出
torch.onnx.export(
    model,
    dummy_input,
    "tof_model.onnx",
    input_names=['input'],
    output_names=['output'],
    dynamic_axes={'input': {0: 'batch_size'}, 'output': {0: 'batch_size'}},
    opset_version=11
)

print("[INFO] 模型成功导出为 ONNX 格式！")
