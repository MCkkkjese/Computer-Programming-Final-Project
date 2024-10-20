# coding=Big5
import os

a=65
print("a = \"{}\"\n".format(chr(a)))
print("ASCII code : a = \"{}\"".format(a))
print("bin a = {}\n".format(bin(a).lstrip("0b")))

print("Dec ~a = {}".format(~a))
print("Dec a << 1 = {}".format(a << 1))
print("Dec a >> 1 = {}\n".format(a >> 1))

a_NOT = bin(~a).lstrip("0b")  # 數值有問題需驗證
a_LEFT = bin(a << 1).lstrip("0b")
a_RIGHT = bin(a >> 1).lstrip("0b")

print("Bin ~a = {}".format(a_NOT))
print("Bin a << 1 = {}".format(a_LEFT))
print("Bin a >> 1 = {}".format(a_RIGHT))

os.system("PAUSE")

'''
a = "A"

ASCII code : a = "65"
bin a = 1000001

Dec ~a = -66
Dec a << 1 = 130
Dec a >> 1 = 32

Bin ~a = -0b1000010
Bin a << 1 = 10000010
Bin a >> 1 = 100000
請按任意鍵繼續 . . . 
'''