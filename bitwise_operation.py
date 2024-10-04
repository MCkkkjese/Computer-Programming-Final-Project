import os

a, b = 0x41, 0x61  # a="A", b="a"
print("a = {}\nb = {}".format(int(a), int(b)))
print("a&b = {}".format(a&b))
print("a|b = {}".format(a|b))
print("a^b = {}\n".format(a^b))

print("hex a = {}".format(hex(a).lstrip("0x")))
print("hex b = {}".format(hex(b).lstrip("0x")))
print("hex a&b = {}".format(hex(a&b).lstrip("0x")))
print("hex a|b = {}".format(hex(a|b).lstrip("0x")))
print("hex a^b = {}".format(hex(a^b).lstrip("0x")))

os.system("Pause")