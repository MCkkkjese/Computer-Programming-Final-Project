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

    // from 0 to n, get random int  -->  rand()%(n+1)
    cout << "from 0 to n, get random int\nInput n : ";
    times = i;
    int n;
    cin >> n;  
    do {
        cout << rand()%(n+1) << endl;
        times--;
    } while (times!=0);

    // from t to l, get random int  -->  t + rand()%(l-t+1) 
    cout << "from t to l, get random int\nInput t, l : ";
    times = i;
    int t, l;
    cin >> t >> l;  
    do {
        cout << t + rand()%(l-t+1) << endl;
        times--;
    } while (times!=0);

    // Random int probability statistics
    cout << "Random int probability statistics\nInput n : ";
    times = 2e8;
    cin >> n;
    int count[n] = {0};
    do {
        count[rand()%(n+1)]++;
        times--;
    } while (times!=0);
    for (int i = 0; i < n; i++) {
        cout << i << " : " << count[i]/2e8 << endl;
    } 
    
    system("PAUSE");
    return 0;
}