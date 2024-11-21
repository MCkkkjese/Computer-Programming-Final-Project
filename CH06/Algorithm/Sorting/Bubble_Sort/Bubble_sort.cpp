#include <iostream>
using namespace std;
void sort(int arr[], int y) {
    for (int i=0; i<y; i++) {
        for (int n=i+1; n<y; n++) {
            if (arr[i]>arr[n]) {swap(arr[i], arr[n]);}
        }
        cout << arr[i] << " ";
    }    
}

int main() {
    int arr[10] = {1, 3, 45, 23, 54, 12, 65, 34, 665, 33};
    sort(arr, 10);
    cout << endl;

    system("PAUSE");
    return 0;
}