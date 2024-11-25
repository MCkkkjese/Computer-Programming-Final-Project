#include <iostream>
using namespace std;
void swap(int &i, int &n);
void sort(int arr[], int l, bool descend);
void print(int arr[], int l);

int main() {
    int l = 10, arr[10] = {54, 23, 46, 56, 45, 12, 98, 38, 84, 93};
    bool descend;
    print(arr, l);

    cout << "Ascending or Descending? (0/1): ";
    cin >> descend;
    sort(arr, l, descend); 
    print(arr, l);

    system("PAUSE");
    return 0;
}

void swap(int &i, int &n) {
    int temp = i;
    i = n;
    n = temp;
}

void sort(int arr[], int l, bool descend) {
    for (int i=0; i<l-1; i++) {
        for (int n=0; n<l-1-i; n++) {
            if (descend == 0) {
                if (arr[n] > arr[n+1]) {
                    swap(arr[n], arr[n+1]);
                }
            } else {
                if (arr[n] < arr[n+1]) {
                    swap(arr[n], arr[n+1]);
                }
            }
        }
    }
}

void print(int arr[], int l) {
    for (int i=0; i<l; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}