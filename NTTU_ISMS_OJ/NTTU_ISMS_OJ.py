import tkinter as tk
from tkinter import INSERT, messagebox
from Extension_modules import file_directory as fd
from Extension_modules import resolution_checking_process as rcp
from Extension_modules import create_cpp_file as ccf
from Extension_modules import send_email as se
import os
import subprocess
import threading
import time
import ttkbootstrap as ttk

start = False
while(start==False):    # 檢查是否有安裝必要模組
    try:
        import ttkbootstrap as ttk
        import pyautogui
        from PIL import Image, ImageTk
        start = True

    
    except ImportError as e:
        print("錯誤：缺少必要模組 →", e)
        print("提示：請確認是否安裝了所有依賴，或等待自動安裝程序完成。")
        from Extension_modules import install
        install.main()
        os.system("PAUSE")




ver = str("beta.25.08.26")    # 版本號
win = ttk.Window(themename="cerculean")    # 建立視窗
screen_w = win.winfo_screenwidth()
screen_h = win.winfo_screenheight()
# win.geometry(f"{screen_w}x{screen_h}")
win.geometry("1920x1080")
win.overrideredirect(False)
win.title("國立臺北教育大學 eTutor - Version {}".format(ver))
ico_path = fd.path_function("Extension_modules/NTUE_LOGO.ico")
win.iconbitmap(ico_path)
win.withdraw()    # 隱藏視窗



if(rcp.resolution() != (1920, 1080)):
    messagebox.showwarning("解析度警告", "解析度非 1920 x 1080 ，內容顯示或將出現異常")

if(rcp.magnification() != 1.0):
    messagebox.showwarning("縮放比例警告", "縮放比例非 100% ，內容顯示或將出現異常")

class open_GUI:    # 開機畫面
    global win_boot
    default_screensize = ("1920x1080")
    win_boot = tk.Toplevel()
    openPitcherSideX = int(screen_w/6)
    openPitcherSideY = int(screen_h/6)
    win_boot.geometry("{}+{}+{}".format(default_screensize, openPitcherSideX, openPitcherSideY))
    win_boot.overrideredirect(True)
    win_boot.title("國北教eTutor啟動畫面")
    pic_bg_path = fd.path_function("Extension_modules/open_picture.png")
    pic_bg = Image.open(pic_bg_path)
    pic = ImageTk.PhotoImage(pic_bg)
    tk.Label(win_boot, image=pic).place(x=-2, y=-2)
    tk.Label(win_boot, text=("Version " + ver), font=("微軟正黑體", 10)).place(x=1, y=1000)
    

    def close_bootup():
        time.sleep(1)
        win_boot.quit()
        win_boot.destroy()
        win.deiconify()
        win.update_idletasks()

    t = threading.Thread(target=close_bootup)
    t.start()
    win_boot.mainloop()

global time_now, username, Commit_History_path_2 , default_screensize  # 宣告全域變數
time_now = tk.StringVar()
username = tk.StringVar()
username.set("學生未輸入學號")
default_screensize = ("1920x1080")

date_today = str(time.strftime("%Y_%m_%d", time.localtime()))    # 開啟預處理檔案
Commit_History_path = str("Commit_History_{}.dat".format(date_today))
Commit_History_path_2 = fd.path_function("/Source_code/{}".format(Commit_History_path))
outFile = open(Commit_History_path_2, 'w')
outFile.write("Commit History - {}\n".format(time.strftime("%Y_%m_%d", time.localtime())))
outFile.flush()
outFile.close() 

def set_interval(func, sec):    # watchdog
    def func_wrapper():
        set_interval(func, sec)
        func()
    
    timer_set = threading.Timer(sec, func_wrapper)
    timer_set.start()
    return timer_set

def remove_file():    # 移除檔案，用以刪除執行後的exe檔案
    filename = str("Judge.cpp")
    open_file_path = fd.path_function("/Extension_modules/Judge_Program/{}.exe".format(filename.rstrip(".cpp")))
    try:
        os.remove(open_file_path)

    except:
        pass

def win_close():    # 關閉視窗
    index = "#include <iostream>\nusing namespace std;\nint func() {\n    cout << \"Hello NTTU ISMS::OJ\" << endl;\n\n    return 0;\n}"
    ccf.write_temp_code(index)
    remove_file()    
    os._exit(False)

def win_maximize():    # 最大化視窗
    win.geometry("{}+{}+{}".format(default_screensize, 1920, 1080))
    win.overrideredirect(False)

def win_minimize():    # 最小化視窗
    messagebox.showwarning("注意", "若要關閉視窗，請使用 \"Exit\" 按鈕來關閉視窗\n請勿使用視窗右上角 \"X\"") 
    win.overrideredirect(False)
    pyautogui.hotkey("win", "d")

def time_set():    # 時間設定
    time_now.set("Time : " + str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime())))


def clear():    # 清空狀態顯示
    status_output.config(state="normal")
    status_output.delete('1.0', 'end')
    status_output.config(state="disabled")

def insert_status(index):    # 控制狀態顯示
    clear()
    status_output.config(state="normal")
    status_output.insert(INSERT, index)
    status_output.config(state="disabled")

def create_exe():    # 建立exe檔案
    filename = str("Judge.cpp")
    file_path = "cd {} && g++ {} -o {}".format(fd.path_function("/Extension_modules/Judge_Program"), filename, filename.rstrip(".cpp"))
    os.system(file_path)

def judge(QN, path, user):    # Judge程式
    value_QSC = []
    value_source = []
    run_time = 0
    TD_path = fd.path_function("Question_Database/default/TD_def_{}.dat".format(QN))    # 讀取測資
    QSC_path = fd.path_function("Question_Database/default/TD_def_{}.cpp".format(QN))    # 讀取題目

    inFile = open(TD_path, 'r')
    Test_data = list(inFile.readlines())

    for i in range(0, len(Test_data)):
        time_start = time.time()
        process = subprocess.Popen(path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, encoding="utf-8", universal_newlines=True)
        try:
            value = process.communicate(Test_data[i], timeout=1)
            time_end = time.time()
            run_time += (time_end - time_start)
            value_source.append(value)

        except subprocess.TimeoutExpired:
            process.kill()
            value_source.append("Timeout")

        finally:
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
    time_judge = str(time.strftime("%Y_%m_%d %H:%M:%S", time.localtime()))

    if(value_source == value_QSC):
        print("AC")
        insert_status("{} - Accepted\n".format(time_judge))
        status_output.config(state="normal")
        status_output.insert(INSERT, "Execution time = %0.5f s\n\n" % run_time)
        status_output.config(state="disabled")

        print("User : {}, {} AC, time AC : {}".format(user, QN, time_judge))
        outFile = open(Commit_History_path_2, 'a')
        outFile.write("{} - User : {}, {} AC\nExecution time = %0.5f s\n\n".format(time_judge, user, QN) % run_time)
        outFile.flush()
        outFile.close() 

    elif("Timeout" in value_source):
        print("TLE")
        insert_status("{} - Time Limit Exceeded\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))

        messagebox.showerror("TLE", "Time Limit Exceeded")
        print("User : {}, {} TLE, time TLE : {}".format(user, QN, time_judge))
        outFile = open(Commit_History_path_2, 'a')
        outFile.write("{} - User : {}, {} TLE\n\n".format(time_judge, user, QN))
        outFile.flush()
        outFile.close()
    
    else:
        print("WA")
        insert_status("{} - Wrong Answer\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))

        messagebox.showerror("WA", "Wrong Answer")
        print("User : {}, {} WA, time WA : {}".format(user, QN, time_judge))
        outFile = open(Commit_History_path_2, 'a')
        outFile.write("{} - User : {}, {} WA\n\n".format(time_judge, user, QN))
        outFile.flush()
        outFile.close()

    value_source.clear()
    value_QSC.clear()

def submit():    # 提交程式，按鍵觸發
    index = code_input.get('1.0', 'end')
    user = username.get()
    QN = CBB_2.get()
    QN = QN.rstrip("\n")

    def func(index, user, QN):    
        ccf.write_temp_code(index)
        flag = ccf.write_source_code(index, user)
        if(flag == True):
            filename = str("Judge.cpp")
            create_exe()
            open_file_path = fd.path_function("/Extension_modules/Judge_Program/{}".format(filename.rstrip(".cpp")))
            judge(QN, open_file_path, user)

        else:
            insert_status("{} -  Compile Error\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))
            messagebox.showerror("CE", "Compile Error")
            outFile = open(Commit_History_path_2, 'a')
            outFile.write("{} - User : {}, {} CE\n\n".format(str(time.strftime("%Y_%m_%d %H:%M:%S", time.localtime())), user, QN))
            outFile.flush()
            outFile.close()

    if(user == "Student ID unknow"):
        messagebox.showerror("使用者未知", "請輸入學生證號碼")
        pass

    else:
        clear()
        insert_status("{} - submit success\n\n".format(str(time.strftime("%Y/%m/%d %H:%M:%S", time.localtime()))))
        func(index, user, QN)

def Commit_History():    # 開啟Commit History，按鍵觸發
    clear()
    status_output.config(state="normal")
    status_output.insert(INSERT, "Opening Commit History\n\n")
    inFile = open(Commit_History_path_2, 'r')
    index = inFile.read()
    status_output.insert(INSERT, index)
    status_output.config(state="disabled")

def CBB_1_func():    # 下拉式選單1
    selected_option1 = CBB_1.get()   
    CBB_2.config(values=[]) 
    if(selected_option1 == "Default"):
        insert_status("Selected type : Default\n\n")
        QN_path = fd.path_function("Question_Database/default/Question_Number.dat")
        inFile = open(QN_path, 'r')
        options2 = list(inFile.readlines())

    elif(selected_option1 == "Exercise"):
        insert_status("Selected type : Exercise\n\n")
        QN_path = fd.path_function("Question_Database/exercise/Question_Number.dat")
        inFile = open(QN_path, 'r')
        options2 = list(inFile.readlines())

    elif(selected_option1 == "Quiz"):
        insert_status("Selected type : Quiz\n\n")
        QN_path = fd.path_function("Question_Database/quiz/Question_Number.dat")
        inFile = open(QN_path, 'r')
        options2 = list(inFile.readlines())

    elif(selected_option1 == "Competition"):
        insert_status("Selected type : Competition\n\n")
        QN_path = fd.path_function("Question_Database/competition/Question_Number.dat")
        inFile = open(QN_path, 'r')
        options2 = list(inFile.readlines())

    CBB_2.config(values=options2)

def CBB_2_func():    # 下拉式選單2
    selected_option2 = CBB_2.get()
    selected_option2 = selected_option2.rstrip("\n")
    def pic_set(QN):
        pic_question_path = fd.path_function("Question_Database/default/TD_def_{}.png".format(QN))
        pic_question = Image.open(pic_question_path)
        pic_Q = ImageTk.PhotoImage(pic_question)
        question.image = pic_Q 
        tk.Label(win, image=pic_Q).place(x=15, y=205)
        win.update_idletasks()

    insert_status("Selected question : {}\n\n".format(selected_option2))
    pic_set(selected_option2)

class GUI_interface:    # GUI介面
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
    tk.Label(win, image=pic).place(x=-2, y=-2)    # 背景圖片，刪除外框
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
    ttk.Button(win, text=" Commit History ", style="Outline.TButton", command=Commit_History).place(x=1450, y=755, width=460, height=45)
    status_output = tk.Text(win, font=("微軟正黑體", 12))
    status_output.place(x=970, y=810, width=940, height=210)
    status_output.config(state="disabled")

win.mainloop()