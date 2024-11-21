#include <iostream>
using namespace std;
void swap(int &x, int &y) {  // Call By Reference
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int arr[10] = {1, 3, 45, 23, 54, 12, 65, 34, 665, 33};
    for (int i=0; i<10; i++) {
        for (int n=i+1; n<10; n++) {
            if (arr[i]>arr[n]) {swap(arr[i], arr[n]);}
        }
        cout << arr[i] << " ";
    }

    system("PAUSE");
    return 0;
}