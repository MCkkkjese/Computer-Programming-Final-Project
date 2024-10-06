/*
char --> 1byte --> 8bits
char[x] --> (1*x)bytes --> (8*x)bits
string --> 32bytes --> 256bits
*/

#include <iostream>
using namespace std;
int main() {
    string input;
    cout << "¿é¤Jchar©Îstring: ";
    cin >> input;

    if (input.length() == 1) {
        char c = input[0];
        cout << "sizeof(char) = " << sizeof(c) << " bytes" << endl;
    }
    else {
        cout << "sizeof(string) = " << sizeof(input) << " bytes" << endl;
    }

    system("PAUSE");
    return 0;
}
