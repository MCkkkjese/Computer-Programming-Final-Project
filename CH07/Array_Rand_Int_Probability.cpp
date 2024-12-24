#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int rand_Int[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int rand_num;
    for (int i = 0; i < 10e4; i++) {
        rand_num = rand() % 10;
        rand_Int[rand_num]++;
    }

    for (int i = 0; i < 10; i++) {
        cout.setf(ios::fixed);
        cout << "The probability of " << i + 1 << " is " << (double)rand_Int[i] / 10e4 << endl;
    }

    return 0;
}