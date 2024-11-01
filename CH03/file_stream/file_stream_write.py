filename = str(input())
outFile = open(filename, 'w')
outFile.write("Hello from python fstream\n")
outFile.flush()

try:
    while True:
        outFile.write(input())
        outFile.write('\n')
        outFile.flush()

except EOFError:
    pass

outFile.close()