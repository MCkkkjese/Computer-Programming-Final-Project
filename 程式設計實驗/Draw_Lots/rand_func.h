#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define 白色 "color 07"
#define 綠色 "color 02"
#define 開始 "Input the starting number: "
#define 結束 "Input the ending number: "
#define 輸出 "Press 'y' key to draw a number between %d and %d, or press 'Esc' to exit.\n"

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
    if (num == n - i + 1) {
        printf("All numbers have been drawn, press 'Esc' to exit.\n");
        return;
    }
    
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
        pass[num++] = drawn;
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