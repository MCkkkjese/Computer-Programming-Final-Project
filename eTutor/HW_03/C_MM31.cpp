#include <iostream>
using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    int i, t=0;
    while (cin >> i) {
        for(int n=0; n<=i; n++) {
            if(n%2==0 && n%3==0 && n%12!=0) t+=n;
        }
        printf("%d\n", t);
        t=0;
    }
}