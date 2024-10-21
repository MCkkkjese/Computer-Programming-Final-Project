/*
程式設計實驗4.4：使用*字元在螢幕上排列一個高和底各有九個*字元的直角三角形
*/

#include <iostream>
using namespace std;
int main() {
    for(int i=1; i<=9; i++) {
        for(int n=1; n<=i; n++) {
            // printf("%d*%d=%d\t", i, n, i*n);
            printf("*");
        }
        printf("\n");
    }

    system("PAUSE");
    return 0;
}