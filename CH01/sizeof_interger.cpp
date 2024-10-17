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
    cout << "sizeof(unsigned long long) = " << sizeof(z) << "\n\n";

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

    system("PAUSE");
    return 0;
}

/*
sizeof(int) = 4
sizeof(long) = 4
sizeof(long long) = 8
sizeof(unsigned int) = 4
sizeof(unsigned long) = 4
sizeof(unsigned long long) = 8

max int = 2147483647
min int = -2147483648

max long int = 2147483647
min long int = -2147483648

max long long int = 9223372036854775807
min long long int = -9223372036854775808

max unsigned int = 4294967295
min unsigned int = 0

max unsigned long int = 4294967295
min unsignedlong int = 0

max unsigned long long int = 18446744073709551615
min unsigned long long int = 0

請按任意鍵繼續 . . .
*/