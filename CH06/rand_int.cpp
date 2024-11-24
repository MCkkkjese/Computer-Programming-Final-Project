#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    const int i = 10;
    cout << "C++ random int function\n";
    
    // std::rand()
    int times = i;
    do {
        cout << rand() <<endl;
        times--;
    } while (times!=0);

    // std::srand(seed), using std::time(0) as seed
    srand(time(0));

    // from 0 to n, get random int
    cout << "from 0 to n, get random int\nInput n : ";
    times = i;
    int n;
    cin >> n;  
    do {
        cout << rand()%n << endl;
        times--;
    } while (times!=0);

    // from t to l, get random int
    cout << "from t to l, get random int\nInput t, l : ";
    times = i;
    int t, l;
    cin >> t >> l;  
    do {
        cout << (1+rand()%n) << endl;
        times--;
    } while (times!=0);
    
    system("PAUSE");
    return 0;
}