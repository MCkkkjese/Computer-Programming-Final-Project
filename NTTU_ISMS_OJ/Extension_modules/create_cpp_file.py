#coding=UTF-8
import time
import os
import subprocess
import re

def write_source_code(index, user):
    # print("WSC")
    try:
        from Extension_modules import file_directory as fd

    except:
        import file_directory as fd

    dir_path = str(os.path.dirname(__file__))
    dir_path = re.sub("Extension_modules", '', dir_path)
    commit_time = str(time.strftime("%Y_%m_%d_%H_%M_%S", time.localtime()))
    time_now = str(time.strftime("_%m_%d_%Y_%H_%M_%S_", time.localtime()))
    filename = str("source_code_{}_{}.cpp".format(time_now, user))
    filename_2 = fd.path_function("Source_code/{}".format(filename))
    # print(filename_2)
    outFile = open(filename_2, 'w')
    outFile.write(index)
    outFile.flush()
    outFile.close()

    date_today = str(time.strftime("%Y_%m_%d", time.localtime()))
    Commit_History_path = str("Commit_History_{}.dat".format(date_today))
    Commit_History_path_2 = fd.path_function("/Source_code/{}".format(Commit_History_path))
    outFile_2 = open(Commit_History_path_2, 'a')
    outFile_2.write("\"{}\" commited \"{}\" at {}\n".format(user, filename, commit_time))
    outFile_2.flush()
    outFile_2.close()

    file_path = "cd {}Source_code && g++ {} -o {}".format(dir_path, filename, filename.rstrip(".cpp"))
    # print(file_path)
    os.system(file_path)
    flag = os.path.isfile("{}.exe".format(filename_2.rstrip(".cpp")))
    # print(flag)
    return flag
    
    # subprocess.run(file_path)
    # flag = subprocess.check_call(file_path)
    # flag = subprocess.check_output(file_path)
    # print(flag)
    # print(flag)
    # return flag

    open_file_path = "{}Source_code/{}".format(dir_path, filename.replace(".cpp", ""))
    # print(open_file_path)
    # os.system(open_file_path)

def write_temp_code(index):
    # print("WTC")
    try:
        from Extension_modules import file_directory as fd

    except:
        import file_directory as fd

    index = index.replace("main()", "func()")
    filename = str("temp_code.cpp")
    filename_2 = fd.path_function("/Extension_modules/Judge_Program/{}".format(filename))
    outFile = open(filename_2, 'w')
    outFile.write(index)
    outFile.flush()
    outFile.close()