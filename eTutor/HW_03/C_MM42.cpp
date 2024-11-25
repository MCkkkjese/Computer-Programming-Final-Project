#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    int i;
    long double n=0;
    while(cin >> i) {
        for(int t=1; t<=i; t++) {
            n += pow((-1), (t+1))*1/(2*t-1);
        }
        cout.setf(ios::fixed);
        cout << setprecision(3) << n << endl;      
        n=0;  
    }
}