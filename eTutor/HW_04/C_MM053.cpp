#include <iostream>
using namespace std;
int k, n[19];

int find_num(int i) {
    switch (i) {
        case 1: return 1; break;
        case 2: return 4; break;
        case 3: return 1; break;
        case 4: return 5; break;
        case 5: return 9; break;
        case 6: return 2; break;
        case 7: return 6; break;
        case 8: return 5; break;
        case 9: return 3; break;
        case 10: return 5; break;
        case 11: return 8; break;
        case 12: return 9; break;
        case 13: return 7; break;
        case 14: return 9; break;
        case 15: return 3; break;
        case 16: return 2; break;
        case 17: return 3; break;
        case 18: return 8; break;
    }

    return 0;
}

int main() {
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        scanf("%d", &n[i]);
    }
    for (int i=0; i<k; i++) {
        printf("%d\n", find_num(n[i]));
    }
}