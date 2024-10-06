/*
fstream existing_file_append

ofstream outFile("file_name", ios::app); --> 在現有檔案上添加內容
    "outFile", "file_name" --> "可自訂物件名稱", "被添加的檔案名稱"
*/

#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int main() {
    ofstream outFile("fstream_outfile.txt", ios::app); 
    if(!outFile) {cout << "file open error" << '\n';} 

    else {
        string str;
        getline(cin, str);
        outFile << str << '\n' << flush;
    }

    outFile.close();

    system("PAUSE");
    return 0;
}