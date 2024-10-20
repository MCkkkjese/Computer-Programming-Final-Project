/*
bitwise operation 位元運算_2

~ : 位元反轉運算子；bitwise NOT operator
<< : 左移運算子；left shift operator
>> : 右移運算子；right shift operator
*/

#include <iostream>
#include <bitset>
using namespace std;
int main() {
    char a=65;
    printf("a = \"%c\"\n\n", a);
    printf("ASCII code : a = \"%d\"\n", static_cast<int>(a));

    bitset<8> bin_a(a); 
    cout << "bin a = " << bin_a << "\n\n";  // printf()不支援以二進位輸出

    cout << "Dec ~a = " << static_cast<int>(~a) << '\n';
    cout << "Dec a << 1 = " << static_cast<int>(a << 1) << '\n';
    cout << "Dec a >> 1 = " << static_cast<int>(a >> 1) << "\n\n";

    bitset<8> bin_a_NOT(~a);
    bitset<8> bin_a_LEFT(a << 1);
    bitset<8> bin_a_RIGHT(a >> 1);

    cout << "Bin ~a = " << bin_a_NOT << '\n';
    cout << "Bin a << 1 = " << bin_a_LEFT << '\n';
    cout << "Bin a >> 1 = " << bin_a_RIGHT << '\n';

    system("PAUSE");
    return 0;
}

/*
a = "A"

ASCII code : a = "65"
bin a = 01000001

Dec ~a = -66
Dec a << 1 = 130
Dec a >> 1 = 32

Bin ~a = 10111110
Bin a << 1 = 10000010
Bin a >> 1 = 00100000
請按任意鍵繼續 . . .
*/