#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void draw(int i, int n);
void _draw();

int rand_func(int i, int n) {
    srand(time(0));  
    char operation;
    do {
        operation = _getch();
        if (operation == 'y') {
            draw(i, n);
        } else if (operation == 13) {
            _draw();
        } else {
            (operation != 27) ? cout << "Invalid key pressed, press \'y\' key to draw a number, or press \'Esc\' to exit. \n" : cout << "Program terminated. \n";
        }
    } while (operation != 27);

    return 0;
}

void draw(int i, int n) {
    cout << "The drawn number is: " << i + rand() % (n - i + 1) << endl;
}

void _draw() {
    string num;
    char ch;
    while ((ch = _getch()) != 13) { 
        num += ch;
    }
    cout << "The drawn number is: " << num << endl;
}