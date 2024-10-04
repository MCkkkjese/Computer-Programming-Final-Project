#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float x;
    double y;
    long double z;
    cout.setf(ios::fixed);
    x=y=z = 1/3.0;  
    cout << "float, double, long double accuracy\n";
    cout << setprecision(32) << "x= " << x << "\n";
    cout << setprecision(32) << "y= " << y << "\n";
    cout << setprecision(32) << "z= " << z << "\n";

    system("Pause");
    return 0;
}