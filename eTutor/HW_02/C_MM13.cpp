#include <iostream>
using namespace std;
int count(int i, int n) {
    return ((i*=60)+n);
}

int main() {
    int hour_1, minute_1, hour_2, minute_2, total;
    scanf("%d %d", &hour_1, &minute_1);
    scanf("%d %d", &hour_2, &minute_2);

    total = count(hour_2, minute_2) - count(hour_1, minute_1);

    switch (total<=120 ? 1 : 2) {
        case (1): total<=30 ? printf("%d\n", 30) : printf("%d\n", (total/30)*30); break;
        case (2): total<=150 ? printf("%d\n", 160) : total<=240 ? printf("%d\n", (((total/30)-4)*40)+120) : printf("%d\n", (((total/30)-8)*60)+280); break;
    }    
}