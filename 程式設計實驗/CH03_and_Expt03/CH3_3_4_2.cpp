#include <iostream>
#include <conio.h>
using namespace std;
int main() {
    char c;
    while ((c=_getche()) != 27) {  // 按ESC跳出迴圈，ESC的ASCII Code == 27
        switch (c) {
            case '1': printf(" --> 壹\n"); break;
            case '2': printf(" --> 貳\n"); break;
            case '3': printf(" --> 參\n"); break;
            case '4': printf(" --> 肆\n"); break;
            case '5': printf(" --> 伍\n"); break;
            case '6': printf(" --> 陸\n"); break;
            case '7': printf(" --> 柒\n"); break;
            case '8': printf(" --> 捌\n"); break;
            case '9': printf(" --> 玖\n"); break;
            case '0': printf(" --> 零\n"); break;
            default: printf(" 請重新輸入\n");
        }
    }

    system("PAUSE");
    return 0;
}