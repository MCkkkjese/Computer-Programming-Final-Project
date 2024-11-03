#coding=UTF-8
import time
import os
import re

def write_source_code(index, user):
    try:
        from Extension_modules import file_directory

    except:
        import file_directory

    dir_path = str(os.path.dirname(__file__))
    dir_path = re.sub("Extension_modules", '', dir_path)
    time_now = str(time.strftime("_%m_%d_%Y_%H_%M_%S_", time.localtime()))
    filename = str("source_code_{}_{}.cpp".format(time_now, user))
    filename_2 = file_directory.path_function("/Source_code/{}".format(filename))
    outFile = open(filename_2, 'w')
    outFile.write(index)
    outFile.flush()
    outFile.close()

    file_path = "cd {}Source_code && g++ {} -o {}".format(dir_path, filename, filename.rstrip(".cpp"))
    # print(file_path)
    os.system(file_path)

    open_file_path = "{}Source_code\{}".format(dir_path, filename.replace(".cpp", ""))
    # print(open_file_path)
    os.system(open_file_path)