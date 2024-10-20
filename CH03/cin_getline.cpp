/*
cin.getline(variable, length, '\n')
*/

#include <iostream>
using namespace std;
int main() {
    char h[128];
    cout << "輸入 : abcdefg123456789" << '\n';
    cin.getline(h, 8);  // 實際取值七個字元 --> [][][][][][][]['\0']
    cout << h << '\n';

    system("PAUSE");
    return 0;
}

/*
輸入 : abcdefg123456789
abcdefg123456789
abcdefg
請按任意鍵繼續 . . .
*/