import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import Dataset, DataLoader
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
import os

# ==== Config ====
csv_path = 'tof_posture_data.csv'
batch_size = 64
num_epochs = 100
learning_rate = 0.001
num_classes = 5  # 根据你实际的类别数
model_save_path = 'posture_cnn_model.pth'

# ==== Dataset ====
class TOFDataset(Dataset):
    def __init__(self, df, label_encoder):
        self.X = df.iloc[:, :-1].values.astype(np.float32).reshape(-1, 1, 8, 8)
        self.y = label_encoder.transform(df['label'])
        

    def __len__(self):
        return len(self.X)

    def __getitem__(self, idx):
        return torch.tensor(self.X[idx], dtype=torch.float32), torch.tensor(self.y[idx], dtype=torch.long)

# ==== CNN Model ====
class TOFPostureCNN(nn.Module):
    def __init__(self, num_classes):
        super(TOFPostureCNN, self).__init__()
        self.conv1 = nn.Conv2d(1, 16, kernel_size=3, padding=1)
        self.bn1 = nn.BatchNorm2d(16)
        self.conv2 = nn.Conv2d(16, 32, kernel_size=3, padding=1)
        self.bn2 = nn.BatchNorm2d(32)
        self.pool = nn.MaxPool2d(2, 2)
        self.fc1 = nn.Linear(32 * 2 * 2, 128)
        self.dropout = nn.Dropout(0.3)
        self.fc2 = nn.Linear(128, num_classes)

    def forward(self, x):
        x = self.pool(F.relu(self.bn1(self.conv1(x))))  # -> 16x4x4
        x = self.pool(F.relu(self.bn2(self.conv2(x))))  # -> 32x2x2
        x = x.view(-1, 32 * 2 * 2)
        x = self.dropout(F.relu(self.fc1(x)))
        x = self.fc2(x)
        return x


if __name__ == "__main__":
    # ==== Load Data ====
    df = pd.read_csv(csv_path)
    label_encoder = LabelEncoder()
    label_encoder.fit(df['label'])

    train_df, val_df = train_test_split(df, test_size=0.2, random_state=42, stratify=df['label'])

    train_dataset = TOFDataset(train_df, label_encoder)
    val_dataset = TOFDataset(val_df, label_encoder)

    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
    val_loader = DataLoader(val_dataset, batch_size=batch_size)

    # ==== Setup ====
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    model = TOFPostureCNN(num_classes).to(device)
    criterion = nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)

    # ==== Training Loop ====
    for epoch in range(num_epochs):
        model.train()
        total_loss = 0
        for X_batch, y_batch in train_loader:
            X_batch, y_batch = X_batch.to(device), y_batch.to(device)

            outputs = model(X_batch)
            loss = criterion(outputs, y_batch)

            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

            total_loss += loss.item()

        # Validation
        model.eval()
        correct, total = 0, 0
        with torch.no_grad():
            for X_batch, y_batch in val_loader:
                X_batch, y_batch = X_batch.to(device), y_batch.to(device)
                outputs = model(X_batch)
                _, predicted = torch.max(outputs, 1)
                total += y_batch.size(0)
                correct += (predicted == y_batch).sum().item()

        acc = correct / total * 100
        print(f"Epoch {epoch+1}/{num_epochs} - Loss: {total_loss:.4f} - Val Acc: {acc:.2f}%")

    # ==== Save Model ====
    torch.save(model.state_dict(), model_save_path)
    print(f"[INFO] Model saved to {model_save_path}")
