filename = str(input("Input Filename (without Filename extension): ") + ".cpp")
print("File name = " + filename)

outFile = open(filename, 'w')
index = str(input("Input sorce code : \n"))
while (index != '}'):
    index = str(input())

print(index)