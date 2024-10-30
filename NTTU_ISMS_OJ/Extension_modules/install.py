import os

def program():  
    modules = ["ttkbootstrap", "pyautogui"]  
    print("preparing to install {}".format(modules))
    for i in range(0, len(modules)):
        os.system("pip install "+modules[i])