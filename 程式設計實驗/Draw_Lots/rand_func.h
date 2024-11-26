#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

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
            if (operation != 27) {
                printf("Invalid key pressed, press 'y' key to draw a number, or press 'Esc' to exit.\n");
            } else {
                printf("Program terminated.\n");
            }
        }
    } while (operation != 27);

    return 0;
}

void draw(int i, int n) {
    printf("The drawn number is: %d\n", i + rand() % (n - i + 1));
}

void _draw() {
    char num[512];
    char ch;
    int index = 0;
    while ((ch = _getch()) != 13) {
        if (ch >= '0' && ch <= '9') {
            num[index++] = ch;
        }
    }
    num[index] = '\0';
    printf("The drawn number is: %s\n", num);
}