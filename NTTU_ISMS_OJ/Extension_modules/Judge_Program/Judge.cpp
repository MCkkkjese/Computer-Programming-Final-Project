#include <iostream>
#include <fstream>
#include "temp_code.cpp"
using namespace std;
int main() {
    int start_time, end_time, run_time;
    start_time = clock();

    int i = 0, test_value[] = {0};
    do {
        func();  
        i++;      
    } while (test_value[i]!=0);

    end_time = clock();
    run_time = end_time - start_time;
    cout << run_time << '\n';

    return 0;
}