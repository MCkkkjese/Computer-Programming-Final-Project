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

    system("Pause");
    return 0;
}