/*
Pointers are variables that store the memory address of another variable.
Pointers are used to access the memory location of a variable.

The value of a variable can be obtained by preceding the pointer with an asterisk sign (*), known as the dereference operator.
The address of a variable can be obtained by preceding the name of the variable with an ampersand sign (&), known as the address-of operator.

data_type *pointer_name;    // pointer declaration
data_type *pointer_name = &variable_name;    // pointer initialization
    
declare a pointer to an data_type variable  -->  data_type *pointer_name = &variable_name;    // e.g. int *ptr = &num;  
*/

#include <iostream>
using namespace std;
int main() {
    int i = 16, n = 32;
    int *ptr = &i;

    cout << ptr << endl;
    cout << *ptr << endl;

    ptr = &n;
    cout << ptr << endl;
    cout << *ptr << endl;

    return 0;
}