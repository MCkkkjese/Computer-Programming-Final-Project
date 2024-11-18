#coding=UTF-8
start = False
while(start==False):
    try:
        import ttkbootstrap as ttk
        import pyautogui
        from PIL import Image, ImageTk
        start = True

    except ImportError:
        print("ERROR : Essential modules not found")
        from Extension_modules import install
        install.main()   

import tkinter as tk
from tkinter import INSERT, messagebox
# from Extension_modules import file_directory as fd
# from Extension_modules import resolution_checking_process as rcp
# from Extension_modules import create_cpp_file as ccf
import os
import subprocess
import threading
import time

ver = str("Beta")
global win_boot
screensize_boot = ("640x360")
win_boot = ttk.Window(themename="cerculean")
win_boot.geometry("{}+{}+{}".format(screensize_boot, int((1920/2)-320), int((1080/2)-180)))
# win_boot.overrideredirect(True)
win_boot.title("NTTU ISMS::OJ")
# pic_bg_path = fd.path_function("Extension_modules/bootup.png")
pic_bg_path = "C:/Users/eric2/Desktop/Computer-Programming-Final-Project/NTTU_ISMS_OJ/Extension_modules/bootup.png"
pic_bg = Image.open(pic_bg_path)
pic = ImageTk.PhotoImage(pic_bg)
tk.Label(win_boot, image=pic).place(x=0, y=0)

def destroy():
    time.sleep(1)
    win_boot.destroy()
    

t = threading.Thread(target=destroy())
t.start()
win_boot.mainloop()