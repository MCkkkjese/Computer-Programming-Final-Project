#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float height, weight, BMI;
    cout << "height "; cin >> height; 
    cout << "weight "; cin >> weight;
    height/=100;
    BMI = weight/pow(height, 2);

    if(BMI<18.5) {printf("過輕\n");}
    else if(24<BMI<=18.5) {printf("正常\n");}
    else if(27<BMI<=24) {printf("過重\n");}
    else if(30<BMI<=27) {printf("輕度肥胖\n");}
    else if(35<BMI<=30) {printf("中度肥胖\n");}
    else {printf("重度肥胖\n");}

    system("PAUSE");
    return 0;
}