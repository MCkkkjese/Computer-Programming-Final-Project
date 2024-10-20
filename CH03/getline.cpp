/*
getline(cin, variable)，可以解決 "cin << " 輸入字串時，中間無法包含空格的問題

Using getline with string, instead of char[size]
*/

#include <iostream>
using namespace std;
int main() {
    string s;
    cout << "getline測試 --> 輸入 : ABCDE abcde" << '\n';
    getline(cin, s);
    cout << s << '\n';

    s.clear();
    cout << "cin測試 --> 輸入 : ABCDE abcde" << '\n';
    cin >> s;
    cout << s << '\n';

    system("PAUSE");
    return 0;
}

/*
getline測試 --> 輸入 : ABCDE abcde
ABCDE abcde
ABCDE abcde
cin測試 --> 輸入 : ABCDE abcde
ABCDE abcde
ABCDE
請按任意鍵繼續 . . . 
*/