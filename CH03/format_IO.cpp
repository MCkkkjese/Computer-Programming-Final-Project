#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES  // for C++
#include <cmath>

using namespace std;
int main() {
    // setw() 設定輸入、輸出長度
    char c[4];  // 三個字元 + ['\0']
    cin >> setw(4) >> c;  // 輸入三個字元 + ['\0']
    cout << c << "\n\n";

    int i = 16;
    cout << '(' << i << ")\n";
    cout << '(' << setw(4) << i << ")\n\n";  // 輸出未滿四個字元時，前方自動補空格

    // setpersion() 設定有效小數點後位數
    cout << setprecision(8) << M_PI << '\n';  // 輸出到小數點後七位 + ['\0']
    cout << fixed << setprecision(8) << M_PI << "\n\n";  // 加上 fixed 嚴格限制輸出到小數點後八位

    // setiosflags() --> 用法為 cin << setiosflags(ios::格式旗號) << value;
    int n = 128;
    cout << n << '\n';
    cout << hex << setiosflags(ios::showbase) << n << "\n\n";

    // 取消 (ios::flags) 狀態
    cout.unsetf(ios::showbase);
    cout << hex << n << "\n\n";

    // setf() --> 作用跟 setiosflags() 相同，用法為 cout.setf(ios::格式旗號);
    cout.setf(ios::showbase);
    cout << hex << n << "\n\n";

    system("PAUSE");
    return 0;
}

/*
ABC
ABC

(16)
(  16)

3.1415927
3.14159265

128
0x80

80

0x80

請按任意鍵繼續 . . .
*/