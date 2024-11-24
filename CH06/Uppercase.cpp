#include <iostream>
#include <cstring>
using namespace std;
void upper(string &str) {  // Call By Reference
    int length = str.size();
    for (int i=0; i<length; i++) {
        if (static_cast<int>(str[i]) >= 97 && static_cast<int>(str[i]) <= 122) {(str[i]) = str[i]-32;}
    }
}

int main() {
    string str;
    getline(cin, str);
    upper(str);
    cout << str << endl;

    system("PAUSE");
    return 0;
}