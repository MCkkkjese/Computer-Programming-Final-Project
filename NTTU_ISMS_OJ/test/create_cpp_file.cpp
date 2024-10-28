#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    string str, filename, index;
    cout << "Input Filename (without Filename extension): ";
    getline(cin, str);
    filename = (str + ".cpp");
    cout << "File name = " << filename << endl;

    ofstream outFile(filename, ios::out);
    if(!outFile) {cout << "file open error" << '\n';} 

    else {
        cout << "Input sorce code :\n";
        do {
            getline(cin, index);
            outFile << index << '\n' << flush;
        } while (index != "}");
    }

    outFile.close();
    system("PAUSE");
    return 0;
}
