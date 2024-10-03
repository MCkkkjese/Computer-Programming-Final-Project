#include <iostream>
#include <limits>
using namespace std;
int main(){
    int i;
    long n;
    long long t;
    unsigned int x;
    unsigned long y;
    unsigned long long z; 

    cout << "sizeof(int) = " << sizeof(i) << "\n";
    cout << "sizeof(long) = " << sizeof(n) << "\n";
    cout << "sizeof(long long) = " << sizeof(t) << "\n";
    cout << "sizeof(unsigned int) = " << sizeof(x) << "\n";
    cout << "sizeof(unsigned long) = " << sizeof(y) << "\n";
    cout << "sizeof(unsigned long long) = " << sizeof(z) << "\n";

    cout << "max int = " << numeric_limits<int>::max() << "\n";
    cout << "min int = " << numeric_limits<int>::min() << "\n\n";
    cout << "max long int = " << numeric_limits<long>::max() << "\n";
    cout << "min long int = " << numeric_limits<long>::min() << "\n\n";
    cout << "max long long int = " << numeric_limits<long long>::max() << "\n";
    cout << "min long long int = " << numeric_limits<long long>::min() << "\n\n";

    cout << "max unsigned int = " << numeric_limits<unsigned int>::max() << "\n";
    cout << "min unsigned int = " << numeric_limits<unsigned int>::min() << "\n\n";
    cout << "max unsigned long int = " << numeric_limits<unsigned long>::max() << "\n";
    cout << "min unsignedlong int = " << numeric_limits<unsigned long>::min() << "\n\n";
    cout << "max unsigned long long int = " << numeric_limits<unsigned long long>::max() << "\n";
    cout << "min unsigned long long int = " << numeric_limits<unsigned long long>::min() << "\n\n";

    system("Pause");
    return 0;
}