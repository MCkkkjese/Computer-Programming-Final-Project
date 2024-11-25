#include <iostream>
#include <cmath>
#define scale_1 1.36
#define scale_2 1.02
#define scale_3 0.998
using namespace std;
int main() {
    int i, n;
    while (scanf("%d", &i) != EOF) {
        n = ((50000 * pow(scale_1, i)) - (10000 * pow(scale_2, i)))/ (35.2 - 0.2 * i);
        printf("The Company will earn %d US dollars after %d year\n", n, i);
    }
}