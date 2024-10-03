a, b = 65, 97
print(chr(a), chr(b))
print("ASCII code : a = \"{}\", b = \"{}\"".format(a, b))
print("bin a = {}\nbin b = {}\n".format(bin(a).lstrip("0b"), bin(b).lstrip("0b")))

print("Dec a&b = {}".format(a&b))
print("Dec a|b = {}".format(a|b))
print("Dec a^b = {}".format(a^b))

a_and_b = bin(a&b).lstrip("0b")
a_or_b = bin(a|b).lstrip("0b")
a_xor_b = bin(a^b).lstrip("0b")

print("Bin a&b = {}".format(a_and_b))
print("Bin a|b = {}".format(a_or_b))
print("Bin a^b = {}".format(a_xor_b))