#include <stdio.h>
#include <stdlib.h>
#include "rand_func.h"

#define 白色 "color 07"
#define 綠色 "color 02"
#define 開始 "Input the starting number: "
#define 結束 "Input the ending number: "
#define 輸出 "Press 'y' key to draw a number between %d and %d, or press 'Esc' to exit.\n"

int main() {
    system(綠色);
    int start, end;
    printf(開始);
    scanf("%d", &start);
    printf(結束);
    scanf("%d", &end);
    printf(輸出, start, end);
    rand_func(start, end);

    system(白色);
    system("PAUSE");
    return 0;
}