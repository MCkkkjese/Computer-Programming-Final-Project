#include <iostream>
using namespace std;
int main() {
    // cin.getline(variable, length, '\n')
    char h[128];
    cin.getline(h, 8);  // 實際輸入七個字元 --> [][][][][][][]['\0']
    cout << h << '\n';

    system("Pause");
    return 0;
}