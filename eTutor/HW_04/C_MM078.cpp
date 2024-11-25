#include <iostream>
using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);

    const unsigned long long value[8]={6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128};
    unsigned long long num_1, num_2;
    int rang_1, rang_2;

    cin >> num_1 >> num_2;
    for (int i=0; i<8; i++) {
        if (num_1 <= value[i]) {
            rang_1 = i;
            break;
        } 
    }

    for (int i=0; i<8; i++) {
        if (num_2 >= value[i]) {
            rang_2 = i;
        }
    }

    if (rang_1 > rang_2 && num_1 != value[rang_1]) {
        cout << "null" << endl;
    } else if (rang_1 >= rang_2 && num_1 == value[rang_1]) {
        cout << value[rang_1] << endl;
    } else {
        for (int i=rang_1; i<=rang_2; i++) {
            cout << value[i];
            if (i != rang_2) {cout << ' ';}
        }
        cout << endl;
    }

    return 0;
}