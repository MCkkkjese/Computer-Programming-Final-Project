#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;
int main() {
    for(int i=-16; i<=16; i++) {
        bitset<8> two_s_complement(i);
        printf("%3d = ", i);
        cout << hex << setiosflags(ios::uppercase) << i << '\n';
    }

    system("PAUSE");
    return 0;
}

/*
-16 = FFFFFFF0
-15 = FFFFFFF1
-14 = FFFFFFF2
-13 = FFFFFFF3
-12 = FFFFFFF4
-11 = FFFFFFF5
-10 = FFFFFFF6
 -9 = FFFFFFF7
 -8 = FFFFFFF8
 -7 = FFFFFFF9
 -6 = FFFFFFFA
 -5 = FFFFFFFB
 -4 = FFFFFFFC
 -3 = FFFFFFFD
 -2 = FFFFFFFE
 -1 = FFFFFFFF
  0 = 0
  1 = 1
  2 = 2
  3 = 3
  4 = 4
  5 = 5
  6 = 6
  7 = 7
  8 = 8
  9 = 9
 10 = A
 11 = B
 12 = C
 13 = D
 14 = E
 15 = F
 16 = 10
請按任意鍵繼續 . . . 
*/