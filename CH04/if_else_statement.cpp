#include <iostream>
using namespace std;
int main() {
    int i, n;
    cin >> i >> n;
    if(i==n) {cout << "i == n\n";}
    else {cout << "i != n\n";}

    char c;
    cin >> c;
    if(c>=65 && c<=90) {printf("char c = %c, ascii c = %d\n", c, static_cast<int>(c));}
    else if(c>=97 && c<=122) {printf("char c = %c, ascii c = %d\n", c, static_cast<int>(c));}
    else {printf("char c != english alphabet, ascii c = %d\n", static_cast<int>(c));}

    system("PAUSE");
    return 0;
}

/*
128 128
i == n
A
char c = A, ascii c = 65
請按任意鍵繼續 . . .
*/

/*
128 256
i != n
a
char c = a, ascii c = 97
請按任意鍵繼續 . . . 
*/

/*
128 128
i == n
@
char c != english alphabet, ascii c = 64
請按任意鍵繼續 . . . 
*/