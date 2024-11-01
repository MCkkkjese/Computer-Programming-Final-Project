#coding=UTF-8
import os
from Extension_modules import file_directory

filename = str(input("Input Filename (without Filename extension): ") + ".cpp")
print("File name = " + filename)
filename = file_directory.path_function("/{}".format(filename))
print("File path = " + filename)

outFile = open(filename, 'w')
index = str(input("Input sorce code : \n"))
outFile.write("{}\n".format(index))
outFile.flush()

outFile = open(filename, 'a')
while (index != '}'):
    index = str(input())
    outFile.write("{}\n".format(index))
    outFile.flush()

outFile.close()
os.system("PAUSE")