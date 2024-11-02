/*
2.4 我們已經知道char是以ASCII碼表示，那麼可以寫程式產生一張類似課本附錄B的對照表嗎？
*/

#include <iostream>
using namespace std;
int main() {
    for(int i=0; i<=128; i++) {
        printf("ASCII %d = %c, ", i, static_cast<char>(i));
        if(i%5==0) {printf("\n");}
    }
    printf("\b\b");

    system("Pause");
    return 0;
}

/*
ASCII 0 = , 
ASCII 1 = , ASCII 2 = , ASCII 3 = , ASCII 4 = , ASCII 5 = , 
ASCII 6 = , ASCII 7 = , ASCII 8 =, ASCII 9 =   , ASCII 10 = 
, 
ASCII 11 = 
, ASCII 12 = 
, ASCII 14 = , ASCII 15 = ,
ASCII 16 = , ASCII 17 = , ASCII 18 = , ASCII 19 = , ASCII 20 = ,
ASCII 21 = , ASCII 22 = , ASCII 23 = , ASCII 24 = , ASCII 25 = ,
ASCII 26 = , ASCII 27 = SCII 28 = , ASCII 29 = , ASCII 30 = ,
ASCII 31 = , ASCII 32 =  , ASCII 33 = !, ASCII 34 = ", ASCII 35 = #,
ASCII 36 = $, ASCII 37 = %, ASCII 38 = &, ASCII 39 = ', ASCII 40 = (,
ASCII 41 = ), ASCII 42 = *, ASCII 43 = +, ASCII 44 = ,, ASCII 45 = -,
ASCII 46 = ., ASCII 47 = /, ASCII 48 = 0, ASCII 49 = 1, ASCII 50 = 2, 
ASCII 51 = 3, ASCII 52 = 4, ASCII 53 = 5, ASCII 54 = 6, ASCII 55 = 7,
ASCII 56 = 8, ASCII 57 = 9, ASCII 58 = :, ASCII 59 = ;, ASCII 60 = <,
ASCII 61 = =, ASCII 62 = >, ASCII 63 = ?, ASCII 64 = @, ASCII 65 = A,
ASCII 66 = B, ASCII 67 = C, ASCII 68 = D, ASCII 69 = E, ASCII 70 = F,
ASCII 71 = G, ASCII 72 = H, ASCII 73 = I, ASCII 74 = J, ASCII 75 = K,
ASCII 76 = L, ASCII 77 = M, ASCII 78 = N, ASCII 79 = O, ASCII 80 = P,
ASCII 81 = Q, ASCII 82 = R, ASCII 83 = S, ASCII 84 = T, ASCII 85 = U,
ASCII 86 = V, ASCII 87 = W, ASCII 88 = X, ASCII 89 = Y, ASCII 90 = Z, 
ASCII 91 = [, ASCII 92 = \, ASCII 93 = ], ASCII 94 = ^, ASCII 95 = _,
ASCII 96 = `, ASCII 97 = a, ASCII 98 = b, ASCII 99 = c, ASCII 100 = d,
ASCII 101 = e, ASCII 102 = f, ASCII 103 = g, ASCII 104 = h, ASCII 105 = i,
ASCII 106 = j, ASCII 107 = k, ASCII 108 = l, ASCII 109 = m, ASCII 110 = n,
ASCII 111 = o, ASCII 112 = p, ASCII 113 = q, ASCII 114 = r, ASCII 115 = s,
ASCII 116 = t, ASCII 117 = u, ASCII 118 = v, ASCII 119 = w, ASCII 120 = x,
ASCII 121 = y, ASCII 122 = z, ASCII 123 = {, ASCII 124 = |, ASCII 125 = }, 
ASCII 126 = ~, ASCII 127 = , ASCII 128 = 請按任意鍵繼續 . . . 
*/