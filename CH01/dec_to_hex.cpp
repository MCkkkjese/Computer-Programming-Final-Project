#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    long long dec_num;
    cout << "輸入一個10進位整數 : ";
    cin >> dec_num;
    cout << hex << dec_num << '\n';

    system("PAUSE");
    return 0;
}

/*
輸入一個10進位整數 : 128
80
請按任意鍵繼續 . . .
*/