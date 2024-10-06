/*
fstream read_file

ifstream inFile("file_name", ios::in); --> 讀取檔案
    "inFile", "file_name" --> "可自訂物件名稱", "被讀取的檔案名稱"

inFile >> object; --> 向 "object" 寫入數據

if(!inFile) or if(inFile.is_open()==false) --> 檢測檔案是否能夠被開啟

inFile.close(); --> 關閉檔案
*/

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inFile("fstream_outfile.txt", ios::in);
    if(!inFile) {cout << "file open error" << '\n';}

    else {
        string str;
        while (getline(inFile, str)) {  // 逐行讀取"file_name"檔案中的內容
            cout << str << '\n';
            str.clear();
        }
    }

    inFile.close();

    system("PAUSE");
    return 0;
}