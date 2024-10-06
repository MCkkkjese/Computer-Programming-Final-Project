/*
cin.width() 和 cout.width() 實驗
*/

#include <iostream>
using namespace std;
int main() {
    char c[128];
    cin.width(8);  // 實際輸入七個字元 --> [][][][][][][]['\0']
    cin >> c;
    cout << c << '\n';

    cout.width(16);  // 輸出小於16字元時，自動補空格
    cout << c << '\n' << c << '\n';  // cout.width() 作用範圍只有一次，第二次就恢復正常輸出

    system("Pause");
    return 0;
}