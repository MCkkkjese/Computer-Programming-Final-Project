#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void draw(int i, int n);
void _draw();
int num = 0, pass[2048] = {0};

int rand_func(int i, int n) {
    srand(time(0));  
    char operation;
    do {
        operation = _getch();
        if (operation == 'y') {
            draw(i, n);
        } else if (operation == 'S') {  // Select
            _draw();
        } else if (operation == 'D') {  // Delete
            char buffer[8]; 
            int index = 0;
            char ch;
            while ((ch = _getch()) != 13 && index < 8) {  // Enter
                if (ch >= '0' && ch <= '9') {
                    buffer[index++] = ch;
                }
            }
            buffer[index] = '\0'; 
            if (index > 0) {
                int number = atoi(buffer); 
                pass[num++] = number;
            }
        } else {
            operation == 27 ? printf("Program terminated.\n") : printf("Invalid key pressed, press 'y' key to draw a number, or press 'Esc' to exit.\n");
        }
    } while (operation != 27);  // Esc

    return 0;
}

void draw(int i, int n) {
    int drawn = i + rand() % (n - i + 1);
    int found = 0;
    for (int j = 0; j < num; j++) {
        if (pass[j] == drawn) {
            found = 1;
            break;
        }
    }
    if (found) {
        draw(i, n);
    } else {    
        printf("The drawn number is: %d\n", drawn);
    }
}

void _draw() {
    char num[1024];
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