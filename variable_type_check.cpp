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

    return 0;
    system("Pause");
}