/*
程式設計實驗2.2：輸入一個字元，輸出其對應的8進位、10進位、及16進位ASCII碼。
*/

#include <iostream>
using namespace std;
int main() {
    char c;
    cin >> c;

    cout.setf(ios::showbase);
    cout << "Oct ASCII = " << oct << static_cast<int>(c) << '\n';
    cout << "Dec ASCII = " << dec << static_cast<int>(c) << '\n';
    cout << "Hex ASCII = " << hex << static_cast<int>(c) << '\n';

    system("PAUSE");
    return 0;
}