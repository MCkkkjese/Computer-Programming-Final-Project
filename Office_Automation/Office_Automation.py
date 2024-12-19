flag = False
while not flag:
    try:
        import os
        import tkinter as tk
        import ttkbootstrap as ttk
        from PIL import Image, ImageTk
        import pandas as pd
        import numpy as np
        import openpyxl
        import matplotlib
        from matplotlib import pyplot as plt
        import mplfinance as mpf
        import yfinance as yf
        import time
        import selenium
        from selenium import webdriver
        flag = True

    except ImportError :
        print("ERROR : Essential components missed. Automatically installing...")
        from Extension_Modules import install
        install.main()
        # print("Press any key to continue...")
        os.system("PAUSE")

from Extension_Modules import file_directory as fd
from Extension_Modules import get_username as gu
print("Application booting up successfully.")

global ticker_list
ticker_list = []

def yf_data_existance(ticker):
    try:
        yf.Ticker(ticker).history(period="1d")
        return True
    except:
        return False

def main():
    win = ttk.Window(themename="cerculean")
    win.title("Office Automation - Automatic Stock Data Analysis")
    win.geometry("1280x720")
    win.resizable(False, False)
    ico_path = fd.path_function("/NTTU_LOGO.ico")
    win.iconbitmap(ico_path)
    pic_bg_path = fd.path_function("/background.png")
    pic_bg = Image.open(pic_bg_path)
    pic = ImageTk.PhotoImage(pic_bg)
    tk.Label(win, image=pic).place(x=-2, y=-2)

    global stc_sym, date_from, date_to, status_output, rest_stock_output
    stc_sym = tk.StringVar()
    date_from = tk.StringVar()
    date_to = tk.StringVar()

    date_from.set("YYYY/MM/DD")
    date_to.set("YYYY/MM/DD")

    tk.Label(win, text="Symbol", font=("Arial", 20)).place(x=10, y=85)
    tk.Entry(win, font=("Arial", 20), textvariable=stc_sym).place(x=10, y=130, width=430, height=40)
    tk.Button(win, text="Apply", font=("Arial", 20)).place(x=450, y=130, width=180, height=40)
    tk.Label(win, text="Resently Searched", font=("Arial", 20)).place(x=10, y=190)
    rest_stock_output = tk.Text(win, font=("Arial", 20))
    rest_stock_output.place(x=10, y=235, width=620, height=175)
    rest_stock_output.config(state="disabled")
    tk.Button(win, text="Apply All", font=("Arial", 20)).place(x=10, y=420, width=620, height=40)

    tk.Label(win, text="Date From", font=("Arial", 20)).place(x=640, y=85)
    tk.Entry(win, font=("Arial", 20), textvariable=date_from).place(x=640, y=130, width=310, height=40)
    tk.Label(win, text="Date To", font=("Arial", 20)).place(x=960, y=85)
    tk.Entry(win, font=("Arial", 20), textvariable=date_to).place(x=960, y=130, width=310, height=40)

    tk.Label(win, text="Stock Information Function", font=("Arial", 20)).place(x=640, y=190)
    PTC = tk.Checkbutton(win, text="Price Trend Chart", font=("Arial", 18)).place(x=640, y=235)
    VC = tk.Checkbutton(win, text="Volume Chart", font=("Arial", 18)).place(x=640, y=270)
    CC = tk.Checkbutton(win, text="Candlestick Chart", font=("Arial", 18)).place(x=640, y=305)
    MAC = tk.Checkbutton(win, text="Moving Average Chart", font=("Arial", 18)).place(x=640, y=340)
    RSI = tk.Checkbutton(win, text="RSI Chart", font=("Arial", 18)).place(x=640, y=375)
    BOL = tk.Checkbutton(win, text="Bollinger Band Chart", font=("Arial", 18)).place(x=640, y=410)
    

    tk.Label(win, text="Status", font=("Arial", 20)).place(x=10, y=475)
    status_output = tk.Text(win, font=("Arial", 20))
    status_output.place(x=10, y=520, width=1260, height=100)
    status_output.config(state="disabled")

    tk.Button(win, text="Stock List", font=("Arial", 20)).place(x=10, y=635, width=200, height=40)
    tk.Button(win, text="Search - Yahoo Finance", font=("Arial", 20)).place(x=220, y=635, width=400, height=40)

    win.mainloop()

if __name__ == "__main__":
    main()