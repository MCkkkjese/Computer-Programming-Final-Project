#include <iostream>
using namespace std;

int gcd(int m, int n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int main() {
    int i, n;
    cin >> i >> n;
    cout << gcd(i, n) << '\n';
}
