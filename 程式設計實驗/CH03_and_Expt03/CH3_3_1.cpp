#include <iostream>
using namespace std;
int main() {
    int i;
    while (scanf("%d", &i) != EOF) {
        (i%2==0) ? printf("Odd number\n") : printf("even number\n");
    }

    system("PAUSE");
    return 0;
}