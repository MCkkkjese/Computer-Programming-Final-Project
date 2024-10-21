/*
程式設計實驗2.1：輸入圓的半徑，求其面積及周長，並表示至小數點下兩位。
*/

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float f;
    double area, peri;

    cin >> f;
    area = pow(f, 2)*M_PI;
    peri = 2*f*M_PI;

    cout.setf(ios::fixed);
    cout << "area = " << setprecision(2) << area << '\n';
    cout << "perimeter = " << setprecision(2) << peri << '\n';

    system("PAUSE");
    return 0;
}