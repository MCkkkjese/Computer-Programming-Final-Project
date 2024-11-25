#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int i, n, t, l, total, r1, r5, r50;
    const int a1=15, a2=20, a3=30;
    scanf("%d, %d, %d, %d", &i, &n, &t, &l);

    total = n*a1+t*a2+l*a3;
    i-=total;
    if(i<0) {printf("0\n");}
    else {
        r50 = i/50;
        i%=50;
        r5 = i/5;
        i%=5;
        r1 = i/1;
    
        printf("%d,%d,%d\n", r1, r5, r50);
    }
}