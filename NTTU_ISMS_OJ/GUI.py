#coding=Big5
start = False
while(start==False):
    try:
        import ttkbootstrap as ttk
        import pyautogui
        from PIL import Image, ImageTk
        start = True

    except:
        print("ERROR : Essential modules not found")
        from Extension_modules import install
        install.program()   

import tkinter as tk
from tkinter import INSERT, messagebox
from Extension_modules import file_directory
from Extension_modules import resolution_checking_process as rcp
import os
import threading
import time

ver = str("Beta")
screensize = ("1920x1080")
win = ttk.Window(themename="cerculean")
win.geometry(screensize)
win.overrideredirect(True)
win.title("NTTU ISMS::OJ")
ico_path = file_directory.path_function("Extension_modules/NTTU_LOGO.ico")
win.iconbitmap(ico_path)

if(rcp.resolution() != (1920, 1080)):
    messagebox.showwarning("解析度警告", "解析度非 1920 x 1080，內容顯示或將出現異常") 
    
def set_interval(func, sec):
    def func_wrapper():
        set_interval(func, sec)
        func()
    
    timer_set = threading.Timer(sec, func_wrapper)
    timer_set.start()
    return timer_set

def win_close():
    os._exit(False)

def win_maximize():
    win.overrideredirect(True)

def win_minimize():
    win.overrideredirect(False)
    pyautogui.hotkey("win", "d")

def time_set():
    time_now.set(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))

class GUI_interface:
    global time_now
    time_now = tk.StringVar()
    set_interval(time_set, 1)

    win_style = ttk.Style()
    win_style.configure('Outline.TButton', font=("微軟正黑體", 14))

    pic_bg_path = file_directory.path_function("Extension_modules/back_ground.png")
    pic_bg = Image.open(pic_bg_path)
    pic = ImageTk.PhotoImage(pic_bg)

    tk.Label(win, image=pic).place(x=0, y=0)
    ttk.Button(win, text=" Exit ", style="Outline.TButton", command=win_close).place(x=1845, y=15)
    ttk.Button(win, text=" Maximize ", style="Outline.TButton", command=win_maximize).place(x=1715, y=15)
    ttk.Button(win, text=" Minimize ", style="Outline.TButton", command=win_minimize).place(x=1585, y=15)
    tk.Label(win, textvariable=time_now, font=("微軟正黑體", 16)).place(x=1705, y=65)
    ttk.Label(win, text=("Version " + ver), font=("微軟正黑體", 10)).place(x=1835, y=120)

    pic_demo_path = file_directory.path_function("Extension_modules/DEMO.png")
    pic_demo = Image.open(pic_demo_path)
    pic_2 = ImageTk.PhotoImage(pic_demo)
    tk.Label(win, image=pic_2).place(x=10, y=145)

    code_input = tk.Text(win, font=("微軟正黑體", 16))
    code_input.place(x=970, y=145, width=940, height=600)
    ttk.Button(win, text=" Submit ", style="Outline.TButton").place(x=970, y=755, width=940, height=45)
    status_output = tk.Text(win, font=("微軟正黑體", 14))
    status_output.place(x=970, y=810, width=940, height=210)

win.mainloop()