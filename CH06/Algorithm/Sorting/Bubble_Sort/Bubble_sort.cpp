// Bubble Sort - The last element finish sorting first. 

#include <iostream>
using namespace std;
void swap(int &i, int &n) {
    int temp = i;
    i = n;
    n = temp;
}

void sort(int arr[], int l) {
    for (int i=0; i<l-1; i++) {
        for (int n=0; n<l-1-i; n++) {
            if (arr[n] > arr[n+1]) {swap(arr[n], arr[n+1]);}
        }
    }
}

void print(int arr[], int l) {
    for (int i=0; i<l; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int l = 10, arr[10] = {54, 23, 46, 56, 45, 12, 98, 38, 84, 93};
    sort(arr, l);
    print(arr, l);

    system("PAUSE");
    return 0;
}