import serial
import matplotlib.pyplot as plt
import numpy as np
import re

# 串口配置
SERIAL_PORT = 'COM13'
BAUD_RATE = 115200

# 正则表达式
pattern = re.compile(r'Zone(\d+)_Status(\d+)_Distance(\d+);')

# 打开串口
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)

# 初始化热图
plt.ion()
fig, ax = plt.subplots()
im = ax.imshow(np.zeros((8, 8)), cmap='hot', vmin=0, vmax=2000)
plt.title("VL53L5CX TOF Heatmap")
plt.colorbar(im)

# 缓存区
collecting_frame = False
expected_zone = 0
frame_data = [0] * 64

try:
    while True:
        line = ser.readline().decode(errors='ignore').strip()
        match = pattern.search(line)
        if not match:
            continue

        zone_id = int(match.group(1))
        if(match.group(2) == '005'):
            distance = int(match.group(3))
        else:
            distance = 2000

        # 1. 起点检测：必须从 Zone00 开始
        if not collecting_frame:
            if zone_id == 0:
                collecting_frame = True
                expected_zone = 1
                frame_data[0] = distance
        else:
            if zone_id == expected_zone:
                frame_data[zone_id] = distance
                expected_zone += 1
                if expected_zone == 64:
                    # 一帧完整，绘图
                    heatmap_data = np.array(frame_data).reshape((8, 8))
                    heatmap_data = np.flipud(np.fliplr(heatmap_data))
                    im.set_data(heatmap_data)
                    plt.pause(0.1)

                    # 重置状态
                    collecting_frame = False
                    expected_zone = 0
            else:
                # 错位了，丢弃帧，重新找 Zone00
                collecting_frame = False
                expected_zone = 0

except KeyboardInterrupt:
    print("退出程序")
finally:
    ser.close()
