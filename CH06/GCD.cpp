#include <iostream>
using namespace std;
int gcd(int i, int n) {
    return (n==0) ?  i : gcd(n, i % n);
}

int main() {
    int i, n;
    cin >> i >> n;
    cout << "GCD of " << i << " and " << n << " is " << gcd(i, n) << endl;

    return 0;
}