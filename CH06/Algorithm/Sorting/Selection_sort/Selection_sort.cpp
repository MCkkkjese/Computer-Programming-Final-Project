// Selection Sort - The first element finish sorting first. 

#include <iostream>
using namespace std;
void swap(int &i, int &n) {  // Call By Reference
    int temp = i;
    i = n;
    n = temp;
}

int main() {
    int arr[10] = {54, 23, 46, 56, 45, 12, 98, 38, 84, 93};
    for (int i=0; i<10; i++) {
        for (int n=i+1; n<10; n++) {
            if (arr[i] > arr[n]) {swap(arr[i], arr[n]);}
        }
        cout << arr[i] << ' ';
    }    
    cout << endl;

    system("PAUSE");
    return 0;
}