import tkinter as tk
from PIL import Image, ImageTk
import threading
import time
import os

global win_boot
screensize_boot = ("640x360")
# win_boot = ttk.Window(themename="cerculean")
win_boot = tk.Toplevel()
win_boot.geometry("{}+{}+{}".format(screensize_boot, int((1920/2)-320), int((1080/2)-180)))
# win_boot.overrideredirect(True)
win_boot.title("NTTU ISMS::OJ")
pic_bg_path = "C:/Users/eric2/Desktop/Computer-Programming-Final-Project/NTTU_ISMS_OJ/Extension_modules/bootup.png"
pic_bg = Image.open(pic_bg_path)
pic = ImageTk.PhotoImage(pic_bg)
tk.Label(win_boot, image=pic).place(x=0, y=0)

def destroy():
    time.sleep(1)
    win_boot.destroy()
    # os._exit(False)
    
t = threading.Thread(target=destroy)
t.start()
win_boot.mainloop()