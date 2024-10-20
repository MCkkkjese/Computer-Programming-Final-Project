#include <iostream>
#include <cstdio>  // 等同於 <stdio.h> ，屬於 C Standard Library ，編譯器支援情況下可以不用提前宣告
using namespace std;
int main() {
    int i, n, t;
    printf("輸入三個10進位整數 : ");
    scanf("%d %d %d", &i, &n, &t);  // scanf("格式", &參數);
    printf("%d %d %d\n", i, n, t);  // printf("格式", 參數);

    printf("輸入一個不包含空格的字串 : ");
    char str[128];  // string s; 無法正常輸入，需要使用 char c[size]，因為 scanf 屬於 C 的語法，不支援 C++ 的 string;
    scanf("%s", &str);  // 字串中間不能包含空格
    printf("%s\n", str);

    system("PAUSE");
    return 0;
}

/*
輸入三個10進位整數 : 1 2 3
1 2 3
輸入一個不包含空格的字串 : ABC123 
ABC123
請按任意鍵繼續 . . . 
*/