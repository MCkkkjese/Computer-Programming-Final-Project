/*
程式設計實驗5.3：已知自然對數的底數 e = 1+(1/1!)+(1/2!)+...+(1/n!) ，請求出其近似值。
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    long double e=1.0, f=1.0;
    int i = 1;

    while (1/f > 1e-128) {
        f*=i;
        e+=1/f;
        cout << i << " : f = " << setprecision(16) << f << ", e = " << e << "\n";
        i++;
    }

    cout << "e = " << setprecision(32) << e << '\n';

    system("PAUSE");
    return 0;
}