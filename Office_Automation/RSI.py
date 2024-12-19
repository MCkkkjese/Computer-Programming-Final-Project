import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt

def calculate_RSI(data, window=14):
    delta = data['Close'].diff()
    gain = (delta.where(delta > 0, 0)).fillna(0)
    loss = (-delta.where(delta < 0, 0)).fillna(0)
    avg_gain = gain.rolling(window=window).mean()
    avg_loss = loss.rolling(window=window).mean()
    rs = avg_gain / avg_loss
    rsi = 100 - (100 / (1 + rs))
    return rsi

# 獲取股票數據
ticker = 'AAPL'
data = yf.download(ticker, start='2020-01-01', end='2023-12-31')

# 計算 RSI
data['RSI'] = calculate_RSI(data)

# 繪製 RSI 圖表
plt.figure(figsize=(14, 7))
plt.plot(data['RSI'], label='RSI')
plt.axhline(70, color='red', linestyle='--')
plt.axhline(30, color='green', linestyle='--')
plt.title(f'{ticker} RSI 圖表')
plt.xlabel('日期')
plt.ylabel('RSI')
plt.legend()
plt.show()
