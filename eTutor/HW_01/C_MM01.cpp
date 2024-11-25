#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float i, n, t, area;
    cin >> i >> n >> t;
    
    area = ((i+n)*t)*0.5;
    cout.setf(ios::showpoint);
    cout << fixed << setprecision(1) << "Trapezoid area:" << area << "\n";
}