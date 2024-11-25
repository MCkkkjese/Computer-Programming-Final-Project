#include <iostream>
using namespace std;
int main() {
    int i;
    while (cin >> i) {
        int n, t;
        n=1;
        t=0;
        while (n<i) {
            t+=n;
            cout << n << " + ";
            n++;
        }
        cout << n << " = " << t+n << '\n';
    }
}