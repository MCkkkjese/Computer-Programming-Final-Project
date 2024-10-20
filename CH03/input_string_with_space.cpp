#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    // 使用 fgets()
    char str_2[128];
    fgets(str_2, sizeof(str_2), stdin);  // fgets(variable, sizeof(variable), stdin);
    printf("%s", str_2);  // fgets() 會自動換行
      
    // 使用 getline()
    string str_3;
    getline(cin, str_3);
    // printf("%s\n", str_3);  // printf() 無法存取string，會出現亂碼
    cout << str_3 << '\n';     
    
    // 使用 scanf()
    char str[128];
    scanf("%[^\n]", &str);  // %[^\n] --> 讀取直到換行，用於讀取包含空格的字串，不建議使用
    printf("%s\n", str); 
    
    system("PAUSE");
    return 0;
}

/*
ABCDE abcde
ABCDE abcde
ABCDE abcde
ABCDE abcde
ABCDE abcde
ABCDE abcde
請按任意鍵繼續 . . .
*/