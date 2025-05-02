import serial
import re
import csv
import threading
from pynput import keyboard
import os

# ==== 串口配置 ====
SERIAL_PORT = 'COM13'        # 改成你自己的串口号
BAUD_RATE = 115200
TIMEOUT = 1

# ==== 标签定义 ====
label_map = {
    '1': 'upright',
    '2': 'left_lean',
    '3': 'right_lean',
    '4': 'backward',
    '5': 'forward'
}

# ==== 全局变量 ====
current_label = None
collecting = False
exit_flag = False
data_buffer = []

zone_pattern = re.compile(r"Zone(\d+)_Status(\d+)_Distance(\d+);")

def serial_reader():
    global data_buffer, collecting, current_label, exit_flag
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        print(f"[INFO] Serial port {SERIAL_PORT} opened.")
    except Exception as e:
        print(f"[ERROR] Failed to open serial port: {e}")
        return

    collecting_frame = False
    expected_zone = 0
    distances = [None] * 64

    while not exit_flag:
        try:
            line = ser.readline().decode('utf-8', errors='ignore').strip()
            if not line:
                continue

            match = zone_pattern.match(line)
            if match:
                zone_index = int(match.group(1))
                if match.group(2) == '005':
                    distance = int(match.group(3))
                else:
                    distance = 2000

                # 检查起点
                if not collecting_frame:
                    if zone_index == 0:
                        collecting_frame = True
                        expected_zone = 1
                        distances = [None] * 64
                        distances[0] = distance
                    else:
                        continue  # 忽略非Zone00起始的帧
                else:
                    if zone_index == expected_zone:
                        distances[zone_index] = distance
                        expected_zone += 1

                        # 一帧完整
                        if expected_zone == 64:
                            if collecting and all(d is not None for d in distances):
                                data_buffer.append(distances + [current_label])
                                print(f"[DATA] Collected {len(data_buffer)} samples (label: {current_label})")
                            collecting_frame = False
                            expected_zone = 0
                    else:
                        # 区块顺序不对，丢弃整帧
                        print(f"[WARN] Zone sequence error: expected Zone{expected_zone:02}, got Zone{zone_index:02}")
                        collecting_frame = False
                        expected_zone = 0
            else:
                print(f"[WARN] Invalid line: {line}")

        except Exception as e:
            print(f"[ERROR] Serial read failed: {e}")
            continue

    ser.close()
    print("[INFO] Serial port closed.")

# ==== 键盘监听线程 ====
def on_press(key):
    global current_label, collecting, exit_flag
    try:
        if key.char in label_map:
            current_label = label_map[key.char]
            collecting = True
            print(f"[INFO] Label set to '{current_label}', collecting started.")
        elif key.char == 's':
            collecting = False
            print("[INFO] Collecting paused.")
    except AttributeError:
        if key == keyboard.Key.esc:
            exit_flag = True
            print("[INFO] Exiting... (saving data)")
            return False  # 结束监听器

# ==== 保存 CSV ====
def save_to_csv(filename="tof_posture_data.csv"):
    if not data_buffer:
        print("[INFO] No data to save.")
        return

    header = [f"zone_{i}" for i in range(64)] + ['label']
    file_exists = os.path.isfile(filename)

    with open(filename, 'a', newline='') as f:  # 使用 'a' 模式追加
        writer = csv.writer(f)
        if not file_exists:
            writer.writerow(header)  # 如果是新文件，写入表头
        writer.writerows(data_buffer)

    print(f"[INFO] Appended {len(data_buffer)} samples to '{filename}'.")

# ==== 主函数 ====
if __name__ == "__main__":
    print("=== TOF 姿态数据采集器 ===")
    print("按键控制说明：")
    print("  1 - 端正坐姿 (upright)")
    print("  2 - 左倾姿态 (left_lean)")
    print("  3 - 右倾姿态 (right_lean)")
    print("  4 - 后仰姿态 (backward)")
    print("  5 - 前倾姿态 (forward)")
    print("  空格 - 暂停采集")
    print("  ESC - 停止并保存退出")
    print("==========================")

    serial_thread = threading.Thread(target=serial_reader)
    serial_thread.start()

    with keyboard.Listener(on_press=on_press) as listener:
        listener.join()

    save_to_csv()
