#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <ctime>
#include <map>
using namespace std;
void drawLotteryWinner(map<int, string>& lottery, map<int, string>::iterator& it, int num) {
    int winner = (rand() % num) + 1;
    it = lottery.find(winner);

    try {
        if (it != lottery.end()) {
            cout << "The winner is: " << it->second << "\nType \'y\' to draw again, or type \'n\' to exit. \n";
            lottery.erase(it);
        } else {
            drawLotteryWinner(lottery, it, num);
        }
    } catch (exception& e) {
        cout << "Error drawing lottery winner" << endl;
    }
}

int main() {
    map<int, string> lottery;
    int num = 0;

    ifstream inFile("isms2024.csv", ios::in);
    if (!inFile) {
        cout << "Error opening file" << endl;
    } else {
        string name;
        while (inFile >> name) {
            lottery.insert(pair<int, string>(num++, name));
        }    
        inFile.close();
    }

    map<int, string>::iterator it;
    srand(time(0));
    char operation;

    cout << "Press \'y\' to draw a lottery winner, or press \'n\' to exit. \n";
    do {
        operation = _getch();
        if (operation == 'y') {
            drawLotteryWinner(lottery, it, num); 
        }
    } while (operation != 'n');

    system("PAUSE");
    return 0;
}