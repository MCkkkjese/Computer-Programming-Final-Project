#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float i;
    cin >> i;
    cout.setf(ios::showpoint);
    cout << fixed << setprecision(1) << i*(9/5.0)+32 << '\n';
}