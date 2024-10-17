#include <iostream>
using namespace std;
int main() {
    char c;
    cout << "input a char : "; cin >> c;

    cout << "Dec ASCII Code : " << static_cast<int>(c) << '\n';
    cout << "Hex ASCII Code : "<< hex << static_cast<int>(c) << '\n';

    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::showbase);
    cout << static_cast<int>(c) << '\n';  // int()和static_cast<int>()作用基本相同
    cout << int(c) << '\n';

    system("PAUSE");
    return 0;
}

/*
input a char : A
Dec ASCII Code : 65
Hex ASCII Code : 41
0x41
0x41
請按任意鍵繼續 . . . 
*/