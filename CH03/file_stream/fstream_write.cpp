/*
fstream new_file_write || overwrite_existing_file

ofstream outFile("file_name", ios::out); --> 創建或複寫檔案
    "outFile", "file_name" --> "可自訂物件名稱", "被創建或被複寫的檔案名稱"

outFile << object; --> 向 "outFile" 寫入數據

if(!outFile) or if(outFile.is_open()==false) --> 檢測檔案是否能夠被開啟

outFile << flush; --> 回寫緩衝區，確保數據立即被寫入，避免造成丟失或延遲
outFile.close(); --> 關閉檔案
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    ofstream outFile("fstream_outfile.txt", ios::out); 
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