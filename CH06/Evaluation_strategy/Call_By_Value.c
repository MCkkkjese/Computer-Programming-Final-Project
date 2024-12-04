#include <stdio.h>
void func(int i, int n) {
    printf("void func : i = %d, n = %d\n", i, n);
    i = 16;
    n = 32;
    printf("void func : set i = 16, set n = 32\n");
    printf("void func : i = %d, n = %d\n", i, n);
}

int main() {
    printf("Call By Value\n");
    int i = 128, n = 256;
    printf("int main : i = %d, n = %d\n", i, n);
    func(i, n);
    printf("int main : i = %d, n = %d\n", i, n);
}