#coding=UTF-8
import time
def write_source_code(index, user):
    try:
        from Extension_modules import file_directory

    except:
        import file_directory

    time_now = str(time.strftime("_%m_%d_%Y_%H_%M_%S_", time.localtime()))
    filename = file_directory.path_function("Source_code/source_code_{}_{}.cpp".format(time_now, user))
    outFile = open(filename, 'w')
    outFile.write(index)
    outFile.flush()
    outFile.close()