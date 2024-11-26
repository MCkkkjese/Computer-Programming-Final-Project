#coding=UTF-8
import os

Question_number = str(input("Input Question number: "))
Test_data = list(map(str, input("Input Test data: ").split(' ')))
filename = "TD_def_{}.dat".format(Question_number)
filename_2 = "TD_def_{}.cpp".format(Question_number)

print(filename)
print(list(Test_data))

outFile = open("NTTU_ISMS_OJ/Question_Database/default/{}".format(filename), 'w')
for i in range(0, len(Test_data)):
    outFile.write("{}\n".format(Test_data[i]))
    outFile.flush()

outFile_2 = open("NTTU_ISMS_OJ/Question_Database/default/{}".format(filename_2), 'w')
index = str(input("Input sorce code: \n"))
outFile_2.write("{}\n".format(index))
outFile_2.flush()

outFile_2 = open("NTTU_ISMS_OJ/Question_Database/default/{}".format(filename_2), 'a')
while (index != '}'):
    index = str(input())
    outFile_2.write("{}\n".format(index))
    outFile_2.flush()

outFile.close()
outFile_2.close()

def oF_3():
    outFile_3 = open("NTTU_ISMS_OJ/Question_Database/default/Question_Number.dat", 'a')
    outFile_3.write("{}\n".format(Question_number))
    outFile_3.flush()
    outFile_3.close()

try:
    oF_3()

except:
    outFile_3 = open("NTTU_ISMS_OJ/Question_Database/default/Question_Number.dat", 'w')
    outFile_3.close()
    oF_3()

'''
Question = map(str, input().split(', '))
# print(list(Question))

outFile = open("Question_Number.dat", 'w')
for i in range(0, len(Question)):
    outFile.write("{}\n".format(Question[i]))
    outFile.flush()

outFile.close()
'''