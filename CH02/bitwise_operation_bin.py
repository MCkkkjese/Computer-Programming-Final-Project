import os

a, b = 65, 97
print("a = \"{}\", b = \"{}\"\n".format(chr(a), chr(b)))
print("ASCII code : a = \"{}\", b = \"{}\"".format(a, b))
print("bin a = {}\nbin b = {}\n".format(bin(a).lstrip("0b"), bin(b).lstrip("0b")))

print("Dec a&b = {}".format(a&b))
print("Dec a|b = {}".format(a|b))
print("Dec a^b = {}\n".format(a^b))

a_and_b = bin(a&b).lstrip("0b")
a_or_b = bin(a|b).lstrip("0b")
a_xor_b = bin(a^b).lstrip("0b")

print("Bin a&b = {}".format(a_and_b))
print("Bin a|b = {}".format(a_or_b))
print("Bin a^b = {}".format(a_xor_b))

os.system("PAUSE")

'''
a = "A", b = "a"

ASCII code : a = "65", b = "97"
bin a = 1000001
bin b = 1100001

Dec a&b = 65
Dec a|b = 97
Dec a^b = 32

Bin a&b = 1000001
Bin a|b = 1100001
Bin a^b = 100000
請按任意鍵繼續 . . . 
'''