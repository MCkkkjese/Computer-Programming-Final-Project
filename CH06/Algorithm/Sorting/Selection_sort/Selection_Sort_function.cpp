// Selection Sort - The first element finish sorting first. 

#include <iostream>
using namespace std;
void swap(int *ptr_i, int *ptr_n) {  // Call By Address
    int temp = *ptr_i;
    *ptr_i = *ptr_n;
    *ptr_n = temp;
}

void sort(int arr[], int l) {
    for (int i=0; i<l; i++) {
        for (int n=i+1; n<l; n++) {
            if (arr[i] > arr[n]) {swap(&arr[i], &arr[n]);}
        }
        cout << arr[i] << ' ';
    }    
    cout << endl;    
}

int main() {
    int l = 10, arr[10] = {54, 23, 46, 56, 45, 12, 98, 38, 84, 93};
    sort(arr, l);

    system("PAUSE");
    return 0;
}