#include <stdio.h>
#include <stdlib.h>
#include "rand_func.h"

#define 開始 "Input the starting number: "
#define 結束 "Input the ending number: "

int main() {
    system("color 02");
    int start, end;
    printf(開始);
    scanf("%d", &start);
    printf(結束);
    scanf("%d", &end);
    printf("Press 'y' key to draw a number between %d and %d, or press 'Esc' to exit.\n", start, end);
    rand_func(start, end);

    system("PAUSE");
    return 0;
}