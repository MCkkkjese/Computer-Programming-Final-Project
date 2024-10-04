#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;
int main() {
    float i;
    double i_2;
    long double n;

    cout << "sizeof(float) = " << sizeof(i) << "\n";
    cout << "sizeof(double) = " << sizeof(i_2) << "\n";
    cout << "sizeof(long double) = " << sizeof(n) << "\n";

    cout << "max float = " << numeric_limits<float>::max() << "\n";
    cout << "min float = " << numeric_limits<float>::min() << "\n\n";
    cout << "max double = " << numeric_limits<double>::max() << "\n";
    cout << "min double = " << numeric_limits<double>::min() << "\n\n";
    cout << "max long double = " << numeric_limits<long double>::max() << "\n";
    cout << "min long double = " << numeric_limits<long double>::min() << "\n";

    system("Pause");
    return 0;
}