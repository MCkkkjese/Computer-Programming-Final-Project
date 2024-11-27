#include <iostream>
#include "rand_func.h"
using namespace std;
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