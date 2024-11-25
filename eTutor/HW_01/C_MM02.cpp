#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float i, n, area;
    cin >> i >> n;
    
    area = (i*n)*0.5;
    cout.setf(ios::showpoint);
    cout << fixed << setprecision(1) << area << "\n";
}