#include <iostream>
#include <cmath>
using namespace std;
int gcd(int m, int n) {
    return m%n == 0 ? n : gcd(n, m%n);
}

int lcm(int m, int n) {
    return abs(m*n)/gcd(m, n);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    int i[128], n=0;
    while (cin >> i[n]) {n++;}
    for (int t=0; t<n-1; t++) {i[t+1] = lcm(i[t], i[t+1]);}
    cout << "Lowest common multiple: " << i[n-1] << '\n';
}