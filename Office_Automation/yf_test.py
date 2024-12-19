import yfinance as yf
import matplotlib.pyplot as plt

# 獲取股票數據
ticker = 'AAPL'
data = yf.download(ticker, start='2020-01-01', end='2023-12-31')

# 繪製價格走勢圖
plt.figure(figsize=(14, 7))
plt.plot(data['Close'], label='Close Price')
plt.title(f'{ticker} 價格走勢圖')
plt.xlabel('日期')
plt.ylabel('價格')
plt.legend()
plt.show()

# 繪製成交量圖
plt.figure(figsize=(14, 7))
plt.bar(data.index, data['Volume'], label='Volume', color='orange')
plt.title(f'{ticker} 成交量圖')
plt.xlabel('日期')
plt.ylabel('成交量')
plt.legend()
plt.show()

# 繪製K線圖
import mplfinance as mpf

mpf.plot(data, type='candle', volume=True, style='yahoo', title=f'{ticker} K線圖')

# 繪製移動平均線圖
data['50_MA'] = data['Close'].rolling(window=50).mean()
data['200_MA'] = data['Close'].rolling(window=200).mean()

plt.figure(figsize=(14, 7))
plt.plot(data['Close'], label='Close Price')
plt.plot(data['50_MA'], label='50 Day MA')
plt.plot(data['200_MA'], label='200 Day MA')
plt.title(f'{ticker} 移動平均線圖')
plt.xlabel('日期')
plt.ylabel('價格')
plt.legend()
plt.show()
