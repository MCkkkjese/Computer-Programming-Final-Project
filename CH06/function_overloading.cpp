#include <iostream>
using namespace std;
void print(int i) {
    cout << "Integer: " << i << endl;
}

void print(double d) {
    cout << "Double: " << d << endl;
}

void print(string str) {
    cout << "String: " << str << endl;
}

int main() {
    cout << "Function Overloading" << endl;
    print(10);    // 調用 void print(int i)
    print(3.14);    // 調用 void print(double d)
    print("Hello");    // 調用 void print(string s)

    return 0;
}