#include <iostream>
using namespace std;
int main() {
    bool flag = true;
    cout << flag << '\n';
    cout << static_cast<int>(flag) << '\n';
    cout << static_cast<bool>(flag) << "\n\n";

    cout.setf(ios::boolalpha);
    cout << flag << '\n';
    cout << static_cast<int>(flag) << '\n';
    cout << static_cast<bool>(flag) << "\n\n";

    flag*=0;  // Bool值可以做運算；意思等同於 --> flag = false;
    cout << flag << '\n';
    cout << static_cast<int>(flag) << '\n';
    cout << static_cast<bool>(flag) << '\n';

    system("PAUSE");
    return 0;
}

/*
1
1
1

true
1
true

false
0
false
請按任意鍵繼續 . . . 
*/