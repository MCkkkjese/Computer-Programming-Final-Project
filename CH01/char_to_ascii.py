import os

c = input("input a char : ")
print("Dec ASCII Code : {}".format(ord(c)))
print("Hex ASCII Code : {}".format(hex(ord(c)).lstrip("0x")))

os.system("PAUSE")