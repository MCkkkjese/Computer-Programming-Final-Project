#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int i, n, t;
    printf("輸入三個10進位整數 : ");
    scanf("%d %d %d", &i, &n, &t);  // scanf("格式", &參數);
    printf("%d %d %d\n", i, n, t);  // printf("格式", 參數);

    printf("輸入一個不包含空格的字串 : ");
    char str[128];  // string s; 無法正常輸入，需要使用 char c[size];
    scanf("%s", &str);  // 字串中間不能包含空格
    printf("%s\n", str);

    system("PAUSE");
    return 0;
}