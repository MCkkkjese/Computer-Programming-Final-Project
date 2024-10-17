#include <typeinfo>
#include <iostream>
using namespace std;
int main() {
    int i;
    float f;
    double d;
    char c[128];
    string s;

    cout << "Input int, float, double, char, string" << '\n';
    cin >> i >> f >> d >> c >> s;
    cout << i << " " << typeid(i).name() << '\n';
    cout << f << " " << typeid(f).name() << '\n';
    cout << d << " " << typeid(d).name() << '\n';
    cout << c << " " << typeid(c).name() << '\n';
    cout << s << " " << typeid(s).name() << '\n';

    cout << "convert int i to double n" << '\n';
    double n = (double)i;
    cout << n << " " << typeid(n).name() << '\n';

    system("PAUSE");
    return 0;
}

/*
Input int, float, double, char, string
2 4.0 8.0 16.0 A Apple
2 i
4 f
8 d
16.0 A128_c
A NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
convert int i to double n
2 d
請按任意鍵繼續 . . . 
*/