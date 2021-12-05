#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define AGE(Y) for(int i = 0; i < Y; ++i)result = strcat(result, #Y)
#define PUT(Y, NUM)     int Y = n / NUM;n -= Y * NUM;AGE(Y)

char *solution(int n) {
    char *result = malloc(sizeof(16));
    PUT(M, 1000);
    PUT(CM, 900);
    PUT(D, 500);
    PUT(CD, 400);
    PUT(C, 100);
    PUT(XC, 90);
    PUT(L, 50);
    PUT(XL, 40);
    PUT(X, 10);
    PUT(IX, 9);
    PUT(V, 5);
    PUT(IV, 4);
    PUT(I, 1);

    return result;
}

int main() {
    printf("%s", solution(2843));

    return 0;
}
