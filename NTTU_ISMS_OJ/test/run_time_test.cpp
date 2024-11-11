#include <iostream>
// #include <ctime>
using namespace std;
int main() {
    long double start_time, end_time;
    start_time = clock();
    cout << start_time << endl;
    for (int i=0; i<=2000; i++) {
        cout << "Hello world" << endl;
    }
    end_time = clock();
    cout << end_time << endl;
    cout << end_time - start_time << " ms" << endl;
}