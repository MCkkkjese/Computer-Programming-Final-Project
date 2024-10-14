/*
_getche() 功能類似於 cin.get() ，但不需要Enter
*/

#include <iostream>
#include <conio.h>
using namespace std;
int main() {
    char c;
    printf("\n%c\n", _getche());

    system("PAUSE");
    return 0;
}