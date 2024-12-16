#include <iostream>
using namespace std;
template <typename T>
void print(T value) {
    cout << "Value: " << value << endl;
}

int main() {
    cout << "Function Template" << endl;
    print(10);    // 調用 print<int>(int value)
    print(3.14);    // 調用 print<double>(double value)
    print("Hello");    // 調用 print<const char*>(const char* value)

    return 0;
}