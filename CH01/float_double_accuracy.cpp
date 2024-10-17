#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float x;
    double y;
    long double z;
    cout.setf(ios::fixed);
    x=y=z = 1/3.0;  
    cout << "float, double, long double accuracy\n";
    cout << setprecision(32) << "x= " << x << "\n";
    cout << setprecision(32) << "y= " << y << "\n";
    cout << setprecision(32) << "z= " << z << "\n";

    system("PAUSE");
    return 0;
}

/*
float, double, long double accuracy
x= 0.33333334326744079589843750000000
y= 0.33333333333333331482961625624739
z= 0.33333333333333331482961625624739
請按任意鍵繼續 . . . 
*/