/*
程式設計實驗4.3：列印九九乘法表
*/

#include <iostream>
using namespace std;
int main() {
    for(int i=1; i<=9; i++) {
        for(int n=1; n<=9; n++) {
            printf("%d*%d=%d\t", i, n, i*n);
        }
        printf("\n");
    }

    system("PAUSE");
    return 0;
}