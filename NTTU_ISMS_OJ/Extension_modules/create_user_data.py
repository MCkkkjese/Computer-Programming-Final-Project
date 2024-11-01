def function():
    ent_1_g = str(ent_1.get())
    ent_2_g = str(ent_2.get())
    username = ent_1_g + ent_2_g
    print("Error") if username=='' else print(username) 
    return username

import tkinter as tk

def set_username(ico_path):
    global ent_1, ent_2, ent_1_g, ent_2_g
    ent_1 = tk.StringVar()
    ent_2 = tk.StringVar()
    
    win = tk.Tk()
    win.geometry("400x170")
    win.title("User Data")
    win.resizable(0, 0)
    win.iconbitmap(ico_path)

    tk.Label(win, text=("Username : "), font=("微軟正黑體", 18)).place(x=16, y=10)
    tk.Label(win, text=("Student ID : "), font=("微軟正黑體", 18)).place(x=10, y=60)
    tk.Entry(win, font=("微軟正黑體", 18), width=16, textvariable=ent_1).place(x=156, y=10)
    tk.Entry(win, font=("微軟正黑體", 18), width=16, textvariable=ent_2).place(x=156, y=60)
    tk.Button(win, text=" Submit ", font=("微軟正黑體", 18), command=function).place(x=10, y=110, width=380)

    win.mainloop()