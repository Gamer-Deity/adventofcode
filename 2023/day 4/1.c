#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 204
#define STR_SIZE 116

int strToInt(char *s, int i0, int *num){
    int i, n;

    for(i = i0, n = 0; s[i] != '\0' && s[i] >= '0' && s[i] <= '9'; i++){
        n *= 10;
        n += (s[i] - '0');
    }

    *num = n;
    return i - i0; /* Returns the number of digits of n */
}

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j;
    int res, n, N0, N, j0, j1, k, pow2, d;
    int *numArray;
    
    memset(cInput, '\0', MAX_LINES * (STR_SIZE + 1));
    for(i = 0; i < MAX_LINES; i++){
        scanf("%c", &c);
        for(j = 0; c != '\n' && c != '\r' && c != '\0' && j < STR_SIZE; j++){
            cInput[i][j] = c;
            scanf("%c", &c);
        }
        scanf("%c", &c);
        cInput[i][j] = '\0';
    }

    /*--------------------------------*/

    for(j = 0; cInput[0][j] != ':'; j++);
    j0 = j;
    for(j = j0; cInput[0][j] != '|'; j++);
    j1 = j;

    N = (STR_SIZE - j0 - 2)/3;
    N0 = (j1 - j0 - 2)/3;

    numArray = (int*)malloc(MAX_LINES * N * sizeof(int));
    k = 0;

    for(i = 0; i < MAX_LINES; i++){
        for(j = j0; j < STR_SIZE; j += d == 0 ? 1 : d){
            d = strToInt(cInput[i], j, &n) ;
            if(n) numArray[k++] = n;
        }
    }

    for(i = 0; i < MAX_LINES; i++){
        pow2 = 1;
        for(j = N0; j < N; j++)
            for(k = 0; k < N0; k++){
                pow2 += pow2 * (numArray[i*N + k] == numArray[i*N + j]);
            }
        res += pow2 / 2;
        /*printf("> %d: [%d, %d(%d)]\n", i, res, pow2, pow2/2);*/
    }
                
    printf("%d", res);
    
    /*--------------------------------*/

    return 0;
}
