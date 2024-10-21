/*
程式設計實驗4.2：輸入一個正整數N，求N!=？
*/

#include <iostream>
using namespace std;
int main() {
    long double f=1.0;
    int i;
    cin >> i;

    for(int n=1; n<=i; n++) {
        f*=n;
        cout << n << "! = " << fixed << f << '\n';
    }
}