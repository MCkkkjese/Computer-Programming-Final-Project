#include <iostream>
#include <ctime>
#include "temp_code.cpp"
using namespace std;
int main() {
    const clock_t start_time = clock();
    cout << start_time << endl;
    func();
    float end_time = clock() - start_time;
    cout << end_time << '\n';
}