#include <iostream>
using namespace std;
int main() {
    int i;
    // scanf("%d", &i);  // scanf() 不知道為何一直影響到後面的輸入
    cin >> i;
    switch (i<=90 ? 1 : 2) {
        case (1): i>=65 ? printf("char i = %c, ascii i = %d\n", static_cast<char>(i), i) : printf("Index out of range\n"); break;
        case (2): i>=97 ? i<=122 ? printf("char i = %c, ascii i = %d\n", static_cast<char>(i), i) : printf("char i != english alphabet, char i = %d\n", static_cast<char>(i)) : printf("Index out of range\n"); break;
    }

    char c;
    // scanf("%c", &c);
    cin >> c;
    switch (c) {
        case ('A'):
        case ('a'): {printf("True\n"); break;}
        default: {printf("char c != 'A' || 'a'\n");}
    }

    system("PAUSE");
    return 0;
}

/*
65
char i = A, ascii i = 65
A
True
請按任意鍵繼續 . . . 
*/