#include <iostream>
#include <vector>
using namespace std;
void swap(int &i, int &n) {
    int temp = i;
    i = n;
    n = temp;
}

void sort(vector<int> &arr) {
    for (int i=0; i<(arr.size()-1); i++) {
        for (int n=0; n<((arr.size()-1)-i); n++) {
            if (arr[n] > arr[n+1]) {swap(arr[n], arr[n+1]);}
        }
    }
}

void print(vector<int> arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {54, 23, 46, 56, 45, 12, 98, 38, 84, 93};
    sort(arr);
    print(arr);

    system("PAUSE");
    return 0;
}