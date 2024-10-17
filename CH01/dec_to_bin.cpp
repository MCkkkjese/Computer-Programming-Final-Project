/*
Dec to Bin --> bitset<length>(variable)
*/

#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
int main() {
    long long dec_num;
    cout << "輸入一個10進位整數 : ";
    cin >> dec_num;

    if(dec_num<=pow(2, 8)) {
        bitset<8> bin_num(dec_num);
        cout << bin_num << '\n';
    }

    else if(dec_num<=pow(2, 16)) {
        bitset<16> bin_num(dec_num);
        cout << bin_num << '\n';
    }

    else if(dec_num<=pow(2, 32)) {
        bitset<32> bin_num(dec_num);
        cout << bin_num << '\n';
    }

    else {
        bitset<64> bin_num(dec_num);
        cout << bin_num << '\n';
    }

    system("PAUSE");
    return 0;
}