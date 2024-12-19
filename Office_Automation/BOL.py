import yfinance as yf
import matplotlib.pyplot as plt

# 獲取股票數據
ticker = 'AAPL'
data = yf.download(ticker, start='2020-01-01', end='2023-12-31')

# 計算 Bollinger Bands
data['20_MA'] = data['Close'].rolling(window=20).mean()
data['20_STD'] = data['Close'].rolling(window=20).std()
data['Upper Band'] = data['20_MA'] + (data['20_STD'] * 2)
data['Lower Band'] = data['20_MA'] - (data['20_STD'] * 2)

# 繪製 Bollinger Bands 圖表
plt.figure(figsize=(14, 7))
plt.plot(data['Close'], label='Close Price')
plt.plot(data['20_MA'], label='20 Day MA')
plt.plot(data['Upper Band'], label='Upper Band', linestyle='--')
plt.plot(data['Lower Band'], label='Lower Band', linestyle='--')
plt.fill_between(data.index, data['Upper Band'], data['Lower Band'], color='grey', alpha=0.1)
plt.title(f'{ticker} Bollinger Bands 圖表')
plt.xlabel('日期')
plt.ylabel('價格')
plt.legend()
plt.show()
