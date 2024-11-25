#include <iostream>
#include <cmath>
using namespace std;
int count(int x) {
    for(int y=1; y<=x; y++) {
        cout << y << "*" << y << "=" << pow(y, 2) << '\n';
    }
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    int i;
    cin >> i;
    count(i);
}