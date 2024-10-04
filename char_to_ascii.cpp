#include <iostream>
using namespace std;
int main() {
    char c;
    cout << "input a char "; cin >> c;

    cout << "Dec ASCII Code : " << static_cast<int>(c) << '\n';
    cout << "Hex ASCII Code : "<< hex << static_cast<int>(c) << '\n';

    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::showbase);
    cout << static_cast<int>(c) << '\n';  // int()和static_cast<int>()作用基本相同
    cout << int(c) << '\n';

    system("Pause");
    return 0;
}