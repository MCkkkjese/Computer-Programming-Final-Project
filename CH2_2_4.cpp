/*
2.4 我們已經知道char是以ASCII碼表示，那麼可以寫程式產生一張類似課本附錄B的對照表嗎？
*/

#include <iostream>
using namespace std;
int main() {
    for(int i=0; i<=256; i++) {
        printf("ASCII %d = %c, ", i, static_cast<char>(i));
        if(i%5==0) {printf("\n");}
    }
    printf("\b\b");

    system("Pause");
    return 0;
}