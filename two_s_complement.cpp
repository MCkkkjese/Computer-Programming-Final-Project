#include <iostream>
#include <bitset>
using namespace std;
int main() {
    for(int i=-16; i<=16; i++) {
        bitset<8> two_s_complement(i);
        printf("%3d = ", i);
        cout << two_s_complement << '\n';
    }

    system("Pause");
    return 0;
}