/*
bitwise operation 位元運算

AND:位元 AND 運算子：&
OR；位元非互斥 OR 運算子：|
XOR；位元互斥 OR 運算子：^
*/

#include <iostream>
using namespace std;
int main() {
    char a=0x41, b=0x61;  // a="A", b="a"

    cout << "a = " << static_cast<int>(a) << "\n";
    cout << "b = " << static_cast<int>(b) << "\n";
    cout << "a&b = " << static_cast<int>(a&b) << "\n";
    cout << "a|b = " << static_cast<int>(a|b) << "\n";
    cout << "a^b = " << static_cast<int>(a^b) << "\n\n";

    cout << hex << "hex a = " << static_cast<int>(a) << "\n";
    cout << hex << "hex b = " << static_cast<int>(b) << "\n";
    cout << hex << "hex a&b = " << static_cast<int>(a&b) << "\n";  
    cout << hex << "hex a|b = " << static_cast<int>(a|b) << "\n";  
    cout << hex << "hex a^b = " << static_cast<int>(a^b) << "\n";  

    system("PAUSE");
    return 0;
}