#coding=UTF-8
import time
import os

def write_source_code(index, user):
    try:
        from Extension_modules import file_directory

    except:
        import file_directory

    time_now = str(time.strftime("_%m_%d_%Y_%H_%M_%S_", time.localtime()))
    filename = str("source_code_{}_{}.cpp".format(time_now, user))
    filename_2 = file_directory.path_function("Source_code/{}".format(filename))
    
    try:
        outFile = open(filename_2, 'w')
        outFile.write(index)
        outFile.flush()
        outFile.close()

    except:
        os.mkdir("/Source_code")
        outFile = open(filename_2, 'w')
        outFile.write(index)
        outFile.flush()
        outFile.close()

    file_path = ("g++ " + filename + " -o " + filename.rstrip(".cpp"))
    print(file_path)
    os.system(file_path)