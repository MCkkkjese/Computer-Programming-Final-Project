#include <iostream>
using namespace std;
int main () {
    int i;
    cout << "輸入一個五位數整數" << endl;
    cin >> i;
    int n=10000;
    do {
        cout << i/n << endl;
        i%=n;
        n/=10;
    } while(n>=1);

    system("PAUSE");
    return 0;
}