#include <iostream>
using namespace std;
int main() {
    char num[128];
    cout << "輸入 : abcdefg123456789" << '\n';
    cin >> num;
    cout << num << '\n';

    cout << "輸入 : abcdefg123456789" << '\n';
    cin.ignore(8); // 忽略下一次get取值的前七個字元 (加一個'\0'，所以是八個字元)
    cin.get(num, 8);
    cout << num << '\n';

    system("PAUSE");
    return 0;
}

/*
輸入 : abcdefg123456789
abcdefg123456789
abcdefg123456789
輸入 : abcdefg123456789
abcdefg123456789
1234567
請按任意鍵繼續 . . .
*/