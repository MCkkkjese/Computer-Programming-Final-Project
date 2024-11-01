#coding=UTF-8
def write_source_code(index):
    try:
        from Extension_modules import file_directory

    except:
        import file_directory

    filename = file_directory.path_function("Source_code/source_code.cpp")
    outFile = open(filename, 'w')
    outFile.write(index)
    outFile.flush()
    outFile.close()