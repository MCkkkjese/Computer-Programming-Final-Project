#include <iostream>
#include <limits>
using namespace std;
int main(){
    short int a;
    int i;
    long n;
    long long t;
    unsigned int x;
    unsigned long y;
    unsigned long long z; 

    cout << "sizeof(short int) = " << sizeof(a) << " bytes" << "\n";
    cout << "sizeof(int) = " << sizeof(i) << " bytes" << "\n";
    cout << "sizeof(long) = " << sizeof(n) << " bytes" << "\n";
    cout << "sizeof(long long) = " << sizeof(t) << " bytes" << "\n";
    cout << "sizeof(unsigned int) = " << sizeof(x) << " bytes" << "\n";
    cout << "sizeof(unsigned long) = " << sizeof(y) << " bytes" << "\n";
    cout << "sizeof(unsigned long long) = " << sizeof(z) << " bytes" << "\n\n";

    cout << "max short int = " << numeric_limits<short int>::max() << "\n";
    cout << "min short int = " << numeric_limits<short int>::min() << "\n\n";
    cout << "max int = " << numeric_limits<int>::max() << "\n";
    cout << "min int = " << numeric_limits<int>::min() << "\n\n";
    cout << "max long int = " << numeric_limits<long>::max() << "\n";
    cout << "min long int = " << numeric_limits<long>::min() << "\n\n";
    cout << "max long long int = " << numeric_limits<long long>::max() << "\n";
    cout << "min long long int = " << numeric_limits<long long>::min() << "\n\n";

    cout << "max unsigned short int = " << numeric_limits<unsigned short int>::max() << "\n";
    cout << "min unsigned short int = " << numeric_limits<unsigned short int>::min() << "\n\n";
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
sizeof(short int) = 2 bytes
sizeof(int) = 4 bytes
sizeof(long) = 4 bytes
sizeof(long long) = 8 bytes
sizeof(unsigned int) = 4 bytes
sizeof(unsigned long) = 4 bytes
sizeof(unsigned long long) = 8 bytes

max short int = 32767
min short int = -32768

max int = 2147483647
min int = -2147483648

max long int = 2147483647
min long int = -2147483648

max long long int = 9223372036854775807
min long long int = -9223372036854775808

max unsigned short int = 65535
min unsigned short int = 0

max unsigned int = 4294967295
min unsigned int = 0

max unsigned long int = 4294967295
min unsignedlong int = 0

max unsigned long long int = 18446744073709551615
min unsigned long long int = 0

請按任意鍵繼續 . . . 
*/