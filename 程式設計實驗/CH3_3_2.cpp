#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float height, weight, BMI;
    cout << "height "; cin >> height; 
    cout << "weight "; cin >> weight;
    height/=100;
    BMI = weight/pow(height, 2);
    cout << BMI << endl;

    system("Pause");
    return 0;
}