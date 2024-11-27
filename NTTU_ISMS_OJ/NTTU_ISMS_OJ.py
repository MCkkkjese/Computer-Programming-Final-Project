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
win.withdraw()

class bootup_GUI:
    global win_boot
    screensize_boot = ("640x360")
    win_boot = tk.Toplevel()
    win_boot.geometry("{}+{}+{}".format(screensize_boot, 640, 360))
    win_boot.overrideredirect(True)
    win_boot.title("NTTU ISMS::OJ")
    pic_bg_path = fd.path_function("Extension_modules/bootup.png")
    pic_bg = Image.open(pic_bg_path)
    pic = ImageTk.PhotoImage(pic_bg)
    tk.Label(win_boot, image=pic).place(x=-2, y=-2)
    tk.Label(win_boot, text=("Version " + ver), font=("微軟正黑體", 10)).place(x=5, y=335)

    def destroy():
        time.sleep(0.5)
        win_boot.quit()
        win_boot.destroy()
        win.deiconify()
        win.update_idletasks()

    t = threading.Thread(target=destroy)
    t.start()
    win_boot.mainloop()

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

def remove_file():
    filename = str("Judge.cpp")
    open_file_path = fd.path_function("/Extension_modules/Judge_Program/{}.exe".format(filename.rstrip(".cpp")))
    try:
        os.remove(open_file_path)

    except:
        pass

def win_close():
    index = "#include <iostream>\nusing namespace std;\nint func() {\n    cout << \"Hello NTTU ISMS::OJ\" << endl;\n\n    return 0;\n}"
    ccf.write_temp_code(index)
    remove_file()    
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
    status_output.config(state="normal")
    status_output.delete('1.0', 'end')
    status_output.config(state="disabled")

def create_exe():
    filename = str("Judge.cpp")
    file_path = "cd {} && g++ {} -o {}".format(fd.path_function("/Extension_modules/Judge_Program"), filename, filename.rstrip(".cpp"))
    os.system(file_path)

def judge(QN, path):
    value_QSC = []
    value_source = []
    run_time = 0
    TD_path = fd.path_function("Question_Database/default/TD_def_{}.dat".format(QN))
    QSC_path = fd.path_function("Question_Database/default/TD_def_{}.cpp".format(QN))

    inFile = open(TD_path, 'r')
    Test_data = list(inFile.readlines())

    for i in range(0, len(Test_data)):
        time_start = time.time()
        process = subprocess.Popen(path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, encoding="utf-8", universal_newlines=True) 
        value = process.communicate(Test_data[i])
        time_end = time.time()
        run_time += (time_end - time_start)
        value_source.append(value)
        process.kill()

    run_time /= len(Test_data)
    inFile_2 = open(QSC_path, 'r')
    QSC = inFile_2.read()
    index = QSC.replace("main()", "func()")
    QSC_filename = str("temp_code.cpp")
    QSC_filename_2 = fd.path_function("/Extension_modules/Judge_Program/{}".format(QSC_filename))
    outFile = open(QSC_filename_2, 'w')
    outFile.write(index)
    outFile.flush()
    outFile.close()
    QSC_filename = str("Judge.cpp")
    create_exe()
    open_file_path_2 = fd.path_function("/Extension_modules/Judge_Program/{}".format(QSC_filename.rstrip(".cpp")))

    for i in range(0, len(Test_data)):
        process_2 = subprocess.Popen(open_file_path_2, stdin=subprocess.PIPE, stdout=subprocess.PIPE, encoding="utf-8", universal_newlines=True) 
        value = process_2.communicate(Test_data[i])
        value_QSC.append(value)
        process_2.kill()
    
    print(run_time)
    print(list(value_source))
    print(list(value_QSC))
    remove_file()

    if(value_source == value_QSC):
        status_output.config(state="normal")
        status_output.insert(INSERT, "{} - Accepted\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))
        status_output.insert(INSERT, "Execution time = %05f s\n\n" % run_time)
        status_output.config(state="disabled")
    
    else:
        status_output.config(state="normal")
        status_output.insert(INSERT, "{} - Wrong Answer\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))
        status_output.config(state="disabled")
        messagebox.showerror("WA", "Wrong Answer")

    value_source.clear()
    value_QSC.clear()

def submit():
    index = code_input.get('1.0', 'end')
    user = username.get()

    def func(index, user):    
        ccf.write_temp_code(index)
        flag = ccf.write_source_code(index, user)

        if(flag == True):
            filename = str("Judge.cpp")
            create_exe()
            open_file_path = fd.path_function("/Extension_modules/Judge_Program/{}".format(filename.rstrip(".cpp")))
            judge("A001", open_file_path)

        else:
            status_output.config(state="normal")
            status_output.insert(INSERT, "{} -  Compile Error\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))
            status_output.config(state="disabled")
            messagebox.showerror("CE", "Compile Error")

    if(user == "Student ID unknow"):
        messagebox.showerror("使用者未知", "請輸入學生證號碼")
        pass

    else:
        clear()
        status_output.config(state="normal")
        status_output.insert(INSERT, "{} - submit success\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))
        status_output.config(state="disabled")
        func(index, user)

def Commit_History():
    clear()
    status_output.config(state="normal")
    status_output.insert(INSERT, "Opening Commit History\n\n")
    inFile = open(Commit_History_path_2, 'r')
    index = inFile.read()
    status_output.insert(INSERT, index)
    status_output.config(state="disabled")

def CBB_1_func():
    selected_option1 = CBB_1.get()

    def insert_status(index):
        clear()
        status_output.config(state="normal")
        status_output.insert(INSERT, index)
        status_output.config(state="disabled")
    
    if(selected_option1 == "Default"):
        insert_status("Selected type : Default\n\n")
        options2 = ["A001", "選項B", "選項C"]

    elif(selected_option1 == "Exercise"):
        insert_status("Selected type : Exercise\n\n")
        options2 = ["選項D", "選項E", "選項F"]

    elif(selected_option1 == "Quiz"):
        insert_status("Selected type : Quiz\n\n")
        options2 = ["選項G", "選項H", "選項I"]

    elif(selected_option1 == "Competition"):
        insert_status("Selected type : Competition\n\n")
        options2 = ["選項J", "選項K", "選項L"]

    CBB_2.config(values=options2)

def CBB_2_func():
    selected_option2 = CBB_2.get()

    def pic_set(QN):
        pic_question_path = fd.path_function("Question_Database/default/TD_def_{}.png".format(QN))
        pic_question = Image.open(pic_question_path)
        pic_Q = ImageTk.PhotoImage(pic_question)
        question.image = pic_Q 
        tk.Label(win, image=pic_Q).place(x=15, y=205)
        win.update_idletasks()

    if(selected_option2 == "A001"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 A001\n\n")
        pic_set("A001")

    elif(selected_option2 == "選項B"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 B\n\n")

    elif(selected_option2 == "選項C"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 C\n\n")

    elif(selected_option2 == "選項D"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 D\n\n")

    elif(selected_option2 == "選項E"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 E\n\n")

    elif(selected_option2 == "選項F"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 F\n\n")

    elif(selected_option2 == "選項G"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 G\n\n")

    elif(selected_option2 == "選項H"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 H\n\n")

    elif(selected_option2 == "選項I"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 I\n\n")

    elif(selected_option2 == "選項J"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 J\n\n")

    elif(selected_option2 == "選項K"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 K\n\n")

    elif(selected_option2 == "選項L"):
        question.delete('1.0', 'end')
        question.insert(INSERT, "題目 L\n\n")

    else:
        pass

class GUI_interface:
    # print("GUI_interface")
    # update_win()
    global question, code_input, status_output, select_option1, select_option2, options2, CBB_1, CBB_2
    set_interval(time_set, 1)

    selected_option1 = tk.StringVar(value=" 選擇類別 ")
    selected_option2 = tk.StringVar(value=" 選擇題目 ")
    options1 = ["Default", "Exercise", "Quiz", "Competition"]
    options2 = []

    win_style = ttk.Style()
    win_style.configure('Outline.TButton', font=("微軟正黑體", 14))

    # scrollbar = tk.Scrollbar(win)
    # scrollbar.pack(side="right", fill="y")

    pic_bg_path = fd.path_function("Extension_modules/background.png")
    pic_bg = Image.open(pic_bg_path)
    pic = ImageTk.PhotoImage(pic_bg)
    tk.Label(win, image=pic).place(x=-2, y=-2)

    # ttk.Button(win, text=" Exit ", style="Outline.TButton", command=win_close).place(x=1845, y=15)
    # ttk.Button(win, text=" Maximize ", style="Outline.TButton", command=win_maximize).place(x=1715, y=15)
    # ttk.Button(win, text=" Minimize ", style="Outline.TButton", command=win_minimize).place(x=1585, y=15)
    # tk.Label(win, textvariable=time_now, font=("微軟正黑體", 16)).place(x=1640, y=65)
    ttk.Button(win, text=" Exit ", style="Outline.TButton", command=win_close).place(x=10, y=980, width=306, height=40)
    ttk.Button(win, text=" Maximize ", style="Outline.TButton", command=win_maximize).place(x=327, y=980, width=306, height=40)
    ttk.Button(win, text=" Minimize ", style="Outline.TButton", command=win_minimize).place(x=643, y=980, width=306, height=40)
    tk.Label(win, textvariable=time_now, font=("微軟正黑體", 18)).place(x=10, y=148)
    ttk.Label(win, text=("Version " + ver), font=("微軟正黑體", 10)).place(x=1835, y=120)

    # ttk.Button(win, text=" Question Database ", style="Outline.TButton", command=question_database).place(x=335, y=145, width=200, height=45)
    CBB_1 = ttk.Combobox(win, font=("微軟正黑體", 16), textvariable=selected_option1, values=options1)
    CBB_1.place(x=335, y=145, width=180)
    CBB_1.bind("<<ComboboxSelected>>", lambda event: CBB_1_func())
    CBB_2 = ttk.Combobox(win, font=("微軟正黑體", 16), textvariable=selected_option2, values=options2)
    CBB_2.place(x=525, y=145, width=180)  
    CBB_2.bind("<<ComboboxSelected>>", lambda event: CBB_2_func())  
    # ttk.Button(win, text=" Commit History ", style="Outline.TButton", command=Commit_History).place(x=545, y=145, width=200, height=45)
    # ttk.Button(win, textvariable=user, style="Outline.TButton", command=user_data).place(x=430, y=145, width=200, height=45)
    ttk.Entry(win, font=("微軟正黑體", 14), textvariable=username).place(x=715, y=145, width=235, height=41)

    question = tk.Text(win, font=("微軟正黑體", 16))
    question.place(x=10, y=200, width=940, height=765)
    # pic_demo_path = fd.path_function("Extension_modules/DEMO.png")
    # pic_demo = Image.open(pic_demo_path)
    # pic_2 = ImageTk.PhotoImage(pic_demo)
    # tk.Label(win, image=pic_2).place(x=15, y=205)

    code_input = tk.Text(win, font=("微軟正黑體", 14))
    # scrollbar.config(command=code_input.yview)
    # code_input.config(yscrollcommand=scrollbar.set)
    code_input.place(x=970, y=145, width=940, height=600)
    ttk.Button(win, text=" Submit ", style="Outline.TButton", command=submit).place(x=970, y=755, width=470, height=45)
    ttk.Button(win, text=" Commit History ", style="Outline.TButton", command=Commit_History).place(x=1450, y=755, width=470, height=45)
    status_output = tk.Text(win, font=("微軟正黑體", 12))
    status_output.place(x=970, y=810, width=940, height=210)
    status_output.config(state="disabled")

win.mainloop()