#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    float i;
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    cin >> i;
    i*=10*i;
    i = (round(i))/10;
    cout.setf(ios::showpoint);
    cout << fixed << setprecision(1) << i << '\n';
}