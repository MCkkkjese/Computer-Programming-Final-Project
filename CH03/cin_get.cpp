#include <iostream>
using namespace std;
int main() {
    char c;
    cin.get(c);  // 第一次輸入的結果會在第一次get取值之後留給第二次get取值用
    cout << c << '\n';

    char h[128];
    cin.get(h, 8);  // 實際取值七個字元 --> [][][][][][][]['\0']
    cout << h << '\n';

    system("PAUSE");
    return 0;
}

/*
ABCDEFGHIJKLMNOPQRSTUVWXYZ
A
BCDEFGH
請按任意鍵繼續 . . . 
*/