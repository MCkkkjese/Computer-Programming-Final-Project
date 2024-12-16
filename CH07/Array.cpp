#include <iostream>
using namespace std;
int main() {
    int num[] = {1, 2, 3, 4, 5};
    float num_f[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char word[6] = "Hello";    // or char word[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char str[2][6] = {"Hello", "World"};

    // Print the array 
    for (int i = 0; i < 5; i++) {
        cout << word[i] << ' ';
    }
    cout << '\n';

    // Print the reversed array 
    for (int i = 4; i >= 0; i--) {
        cout << word[i] << ' ';
    }
    cout << '\n';

    // Select the maximum and minimum values from the array
    int max, min;
    max = min = num[0];
    cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        cout << num[i] << ' ';
        if (num[i] > max) {
            max = num[i];
        }

        if (num[i] < min) {
            min = num[i];
        }
    }
    cout << '\n' << "Max: " << max << ", Min: " << min << '\n';
}