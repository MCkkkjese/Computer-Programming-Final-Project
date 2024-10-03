a, b = 65, 97
print(chr(a), chr(b))
print("ASCII code : a = \"{}\", b = \"{}\"".format(a, b))
print("bin a = {}\nbin b = {}\n".format(bin(a).strip("0b"), bin(b).strip("0b")))

print("Dec a&b = {}".format(a&b))
print("Dec a|b = {}".format(a|b))
print("Dec a^b = {}".format(a^b))

print("Bin a&b = {}".format(int(bin(a).strip("0b"))&int(bin(b).strip("0b"))))
print("Bin a|b = {}".format(int(bin(a).strip("0b"))|int(bin(b).strip("0b"))))
print("Bin a^b = {}".format(int(bin(a).strip("0b"))^int(bin(b).strip("0b"))))