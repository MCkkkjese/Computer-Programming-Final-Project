#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    /*
    // 使用 scanf()
    char str[128];
    scanf("%[^\n]", &str);  // %[^\n] --> 讀取直到換行，用於讀取包含空格的字串
    printf("%s\n", str);
    */

    /*
    // 使用 fgets()
    char str_2[128];
    fgets(str_2, sizeof(str_2), stdin);  // fgets(variable, sizeof(variable), stdin);
    printf("%s\n", str_2);    
    */

    /*
    // 使用 getline()
    string str_3;
    getline(cin, str_3);
    // printf("%s\n", str_3);
    cout << str_3 << '\n';    
    */

   system("PAUSE");
   return 0;
}
