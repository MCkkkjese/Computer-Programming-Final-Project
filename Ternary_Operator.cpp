/*
Ternary Operator
A ? B : C
when A == True --> B
when A == False --> C
*/

#include <iostream>
using namespace std;
int main(){
    int i = 16;
    int n;
    cin >> n;
    (i==n) ? cout << "True" : cout << "False";

    system("Pause");
    return 0;
}