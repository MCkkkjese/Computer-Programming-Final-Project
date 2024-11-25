#include <iostream>
#include <vector>
using namespace std;
void swap(int &i, int &n);
void sort(vector<int> &arr, bool descend);
void print(vector<int> arr);

int main() {
    vector<int> arr = {54, 23, 46, 56, 45, 12, 98, 38, 84, 93};
    bool descend;
    print(arr);

    cout << "Ascending or Descending? (0/1): ";
    cin >> descend;
    sort(arr, descend);
    print(arr);

    system("PAUSE");
    return 0;
}

void swap(int &i, int &n) {
    int temp = i;
    i = n;
    n = temp;
}

void sort(vector<int> &arr, bool descend) {
    for (int i=0; i<(arr.size()-1); i++) {
        for (int n=0; n<((arr.size()-1)-i); n++) {
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

void print(vector<int> arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}