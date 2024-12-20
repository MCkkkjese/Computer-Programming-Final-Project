import yfinance as yf

def check_ticker_exists(ticker):
    try:
        stock = yf.Ticker(ticker)
        info = stock.info
        print(info)  # 調試輸出
        # 檢查多個字段來確定股票是否存在
        if 'regularMarketPrice' in info or 'previousClose' in info:
            return True
        else:
            return False
    except Exception as e:
        print(f"Error: {e}")  # 調試輸出
        return False

# 測試範例
ticker = "BBPL"
if check_ticker_exists(ticker):
    print(f"{ticker} 存在")
else:
    print(f"{ticker} 不存在")