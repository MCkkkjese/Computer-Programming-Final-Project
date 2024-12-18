#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    // printf("formate", variable)
    char str[] = "Hello World";
    printf("%s\n", str);

    // scanf("formate", &variable)
    char str_2[1];
    scanf("%s", &str_2);
    printf("%s\n", str_2);

    return 0;
}
