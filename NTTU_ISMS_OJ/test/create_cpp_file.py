import os

filename = str(input("Input Filename (without Filename extension): ") + ".cpp")
print("File name = " + filename)

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