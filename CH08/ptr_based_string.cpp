#include <iostream>
using namespace std;
int main() {
    // one-dimensional character array
    char chr_arr[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    for (int i=0; i<11; i++) {
        cout << chr_arr[i];
    }
    cout << "\n\n";

    // mulitdimensional string array
    char str_arr[5][12] = {"Hello World", "Hello World", "Hello World", "Hello World", "Hello World"};
    for (int i=0; i<5; i++) {    // column
        for (int n=0; n<11; n++) {    // row
            cout << str_arr[i][n];
        }
        cout << '\n';
    }

    return 0;
}