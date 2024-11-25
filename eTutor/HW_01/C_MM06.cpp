#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    float i;
    cin >> i;
    i*=16;
    i = (round(i))/10;
    cout.setf(ios::showpoint);
    cout << fixed << setprecision(1) << i << '\n';
}