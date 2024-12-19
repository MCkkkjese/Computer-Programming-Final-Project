import os

def main():  
    modules = ["ttkbootstrap", "pandas", "numpy", "openpyxl", "matplotlib", "yfinance", "selenium", "mplfinance"]
    print("preparing to install {}".format(modules))
    for i in range(0, len(modules)):
        os.system("pip install "+modules[i])

if __name__ == "__main__":
    main()