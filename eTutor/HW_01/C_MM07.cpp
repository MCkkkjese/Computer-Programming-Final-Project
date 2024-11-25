#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int i;
    while (cin >> i) {
        cout << i << " " << pow(i, 2) << " " << pow(i, 3) << '\n';
    }
}