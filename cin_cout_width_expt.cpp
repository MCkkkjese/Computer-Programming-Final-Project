#include <iostream>
using namespace std;
int main() {
    // cin.width() 和 cout.width() 實驗
    char c[128];
    cin.width(8);  // 實際輸入七個字元 --> [][][][][][][]['\0']
    cin >> c;
    cout << c << '\n';

    cout.width(16);  // 輸出小於16字元時，自動補空格
    cout << c << '\n';

    system("Pause");
    return 0;
}