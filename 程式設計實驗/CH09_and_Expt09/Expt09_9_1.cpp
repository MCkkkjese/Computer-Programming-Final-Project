#include <iostream> 
using namespace std;
int main() {
    int i = 128;
    int *ptr = &i;
    cout << hex << "ptr = " << ptr << endl;
    cout << dec << "*ptr = " << *ptr << endl;
    cout << dec << "i = " << i << endl << endl;

    *ptr *= 2;
    cout << "After *ptr *= 2" << endl;
    cout << hex << "ptr = " << ptr << endl;
    cout << dec << "*ptr = " << *ptr << endl;
    cout << dec << "i = " << i << endl;

    return 0;
}