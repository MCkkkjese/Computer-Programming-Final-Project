#coding=UTF-8
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
from Extension_modules import file_directory as fd
from Extension_modules import resolution_checking_process as rcp
from Extension_modules import create_cpp_file as ccf
import os
import subprocess
import threading
import time

ver = str("Beta")
screensize = ("1920x1080")
win = ttk.Window(themename="cerculean")
win.geometry(screensize)
win.overrideredirect(True)
win.title("NTTU ISMS::OJ - Version {}".format(ver))
ico_path = fd.path_function("Extension_modules/NTTU_LOGO.ico")
win.iconbitmap(ico_path)

global time_now, username
time_now = tk.StringVar()
username = tk.StringVar()
username.set("Student ID unknow")

date_today = str(time.strftime("%Y_%m_%d", time.localtime()))
Commit_History_path = str("Commit_History_{}.dat".format(date_today))
Commit_History_path_2 = fd.path_function("/Source_code/{}".format(Commit_History_path))
outFile = open(Commit_History_path_2, 'w')
outFile.write("Commit History - {}\n".format(time.strftime("%Y_%m_%d", time.localtime())))
outFile.flush()
outFile.close()

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
    index = "#include <iostream>\nusing namespace std;\nint func() {\n    cout << \"Hello NTTU ISMS::OJ\" << endl;\n\n    return 0;\n}"
    ccf.write_temp_code(index)
    os._exit(False)

def win_maximize():
    win.overrideredirect(True)

def win_minimize():
    messagebox.showwarning("注意", "若要關閉視窗，請使用 \"Exit\" 按鈕來關閉視窗\n請勿使用視窗右上角 \"X\"") 
    win.overrideredirect(False)
    pyautogui.hotkey("win", "d")

def time_set():
    time_now.set("Time : " + str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime())))

def clear():
    status_output.delete('1.0', 'end')

# def submit():
#     user = username.get()
#     clear()
#     status_output.insert(INSERT, user)

def ofp():
    filename = str("Judge.cpp")
    file_path = "cd {} && g++ {} -o {}".format(fd.path_function("/Extension_modules/Judge_Program"), filename, filename.rstrip(".cpp"))
    os.system(file_path)

def judge(QN, path):
    value_QSC = []
    value_source = []
    TD_path = fd.path_function("Question_Database/default/TD_def_{}.dat".format(QN))
    QSC_path = fd.path_function("Question_Database/default/TD_def_{}.cpp".format(QN))

    inFile = open(TD_path, 'r')
    Test_data = list(inFile.readlines())
    # for i in range(0, len(Test_data)):
    #     print(Test_data[i])
    #     Test_data[i] = str(Test_data[i]).replace('\\n', ' ')
    #     print(Test_data[i] + "replaced")

    for i in range(0, len(Test_data)):
        # n = 0
        # def time_lim(n, i):
        #     n+=i
        #     if(n>1):
        #         process.kill()

        # timer = threading.Timer(1, time_lim(n, 1))
        process = subprocess.Popen(path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, encoding="utf-8", universal_newlines=True) 
        # timer.start()
        # print(Test_data[i])
        value = process.communicate(Test_data[i])
        value_source.append(value)
        # print(value)
        # status_output.insert(INSERT, value)
        process.kill()
        # status_output.insert(INSERT, '\n')

    inFile_2 = open(QSC_path, 'r')
    QSC = inFile_2.read()
    index = QSC.replace("main()", "func()")
    QSC_filename = str("temp_code.cpp")
    QSC_filename_2 = fd.path_function("/Extension_modules/Judge_Program/{}".format(QSC_filename))
    outFile = open(QSC_filename_2, 'w')
    outFile.write(index)
    outFile.flush()
    outFile.close()
    # print(index)
    # QSC_filename = str("Judge.cpp")
    # QSC_file_path = "cd {} && g++ {} -o {}".format(fd.path_function("/Extension_modules/Judge_Program"), QSC_filename, QSC_filename.rstrip(".cpp"))
    # os.system(QSC_file_path)
    ofp()
    open_file_path_2 = fd.path_function("/Extension_modules/Judge_Program/{}".format(QSC_filename.rstrip(".cpp")))

    for i in range(0, len(Test_data)):
        process_2 = subprocess.Popen(open_file_path_2, stdin=subprocess.PIPE, stdout=subprocess.PIPE, encoding="utf-8", universal_newlines=True) 
        # print(Test_data[i])
        value = process_2.communicate(Test_data[i])
        value_QSC.append(value)
        # print(value)
        # status_output.insert(INSERT, value)
        process_2.kill()
        # status_output.insert(INSERT, '\n')

    print(list(value_source))
    print(list(value_QSC))

    if(value_source == value_QSC):
        status_output.insert(INSERT, "{} - Accepted\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))
    
    else:
        status_output.insert(INSERT, "{} - Wrong Answer\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))

def submit():
    index = code_input.get('1.0', 'end')
    user = username.get()

    def func(index, user):    
        ccf.write_temp_code(index)
        ccf.write_source_code(index, user)

        # filename = str("Judge.cpp")
        # file_path = "cd {} && g++ {} -o {}".format(fd.path_function("/Extension_modules/Judge_Program"), filename, filename.rstrip(".cpp"))
        # os.system(file_path)
        ofp()

        open_file_path = fd.path_function("/Extension_modules/Judge_Program/{}".format(filename.rstrip(".cpp")))
        # print(open_file_path)
        # os.system(open_file_path)

        # value = subprocess.check_call(open_file_path)
        # print(value)

        # judge = subprocess.Popen(open_file_path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, encoding="utf-8", universal_newlines=True)
        # value = judge.communicate("Admin")
        # stdout = str(stdout).split('\\n')
        # print(value)
        # print(type(value))
        # status_output.insert(INSERT, value)

        judge("A001", open_file_path)

        '''
        value = subprocess.getstatusoutput(open_file_path)
        # value = str(value).split('\n')
        # print(type(value))
        print(value[1])
        status_output.insert(INSERT, value[1])        
        '''

    if(user == "Student ID unknow"):
        messagebox.showerror("使用者未知", "請輸入學生證號碼")
        pass

    else:
        # index = index.replace("main()", "function()")
        clear()
        status_output.insert(INSERT, "{} - submit success\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))
        func(index, user)

def Commit_History():
    clear()
    status_output.insert(INSERT, "Opening Commit History\n\n")
    inFile = open(Commit_History_path_2, 'r')
    index = inFile.read()
    status_output.insert(INSERT, index)

class GUI_interface:
    global question, code_input, status_output
    set_interval(time_set, 1)

    win_style = ttk.Style()
    win_style.configure('Outline.TButton', font=("微軟正黑體", 14))

    # scrollbar = tk.Scrollbar(win)
    # scrollbar.pack(side="right", fill="y")

    pic_bg_path = fd.path_function("Extension_modules/background.png")
    pic_bg = Image.open(pic_bg_path)
    pic = ImageTk.PhotoImage(pic_bg)

    tk.Label(win, image=pic).place(x=0, y=0)
    ttk.Button(win, text=" Exit ", style="Outline.TButton", command=win_close).place(x=1845, y=15)
    ttk.Button(win, text=" Maximize ", style="Outline.TButton", command=win_maximize).place(x=1715, y=15)
    ttk.Button(win, text=" Minimize ", style="Outline.TButton", command=win_minimize).place(x=1585, y=15)
    tk.Label(win, textvariable=time_now, font=("微軟正黑體", 16)).place(x=1640, y=65)
    ttk.Label(win, text=("Version " + ver), font=("微軟正黑體", 10)).place(x=1835, y=120)

    ttk.Button(win, text=" Question Database ", style="Outline.TButton").place(x=10, y=145, width=200, height=45)
    ttk.Button(win, text=" Commit History ", style="Outline.TButton", command=Commit_History).place(x=220, y=145, width=200, height=45)
    # ttk.Button(win, textvariable=user, style="Outline.TButton", command=user_data).place(x=430, y=145, width=200, height=45)
    ttk.Entry(win, font=("微軟正黑體", 14), textvariable=username).place(x=430, y=145, width=520, height=45)

    question = tk.Text(win, font=("微軟正黑體", 16))
    question.place(x=10, y=205, width=940, height=815)
    pic_demo_path = fd.path_function("Extension_modules/DEMO.png")
    pic_demo = Image.open(pic_demo_path)
    pic_2 = ImageTk.PhotoImage(pic_demo)
    tk.Label(win, image=pic_2).place(x=15, y=210)

    code_input = tk.Text(win, font=("微軟正黑體", 14))
    # scrollbar.config(command=code_input.yview)
    # code_input.config(yscrollcommand=scrollbar.set)
    code_input.place(x=970, y=145, width=940, height=600)
    ttk.Button(win, text=" Submit ", style="Outline.TButton", command=submit).place(x=970, y=755, width=940, height=45)
    status_output = tk.Text(win, font=("微軟正黑體", 12))
    status_output.place(x=970, y=810, width=940, height=210)

win.mainloop()