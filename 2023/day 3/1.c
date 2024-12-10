#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 140
#define STR_SIZE 140

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
    char c, cInput[MAX_LINES][STR_SIZE + 1], cText[MAX_LINES + 2][STR_SIZE + 3];
    int i, j;
    int res, n, d, k1, k2, check;

    memset(cInput, '\0', MAX_LINES * STR_SIZE);
    for(i = 0; i < MAX_LINES; i++){
        scanf("%c", &c);
        for(j = 0; c != '\n' && c != '\r' && c != '\0' && j < STR_SIZE; j++){
            cInput[i][j] = c;
            scanf("%c", &c);
        }
        scanf("%c", &c);
        cInput[i][j] = '\0';
    }
    /*for(i = 0; i < MAX_LINES; i++) printf("%s\n", cInput[i]);*/

    /*--------------------------------*/

    memset(cText, '.', (MAX_LINES + 2) * (STR_SIZE + 3));
    cText[0][STR_SIZE + 2] = '\0';
    for(i = 1; i < MAX_LINES + 1; i++){
        for(j = 1; j < STR_SIZE + 1; j++){
            cText[i][j] = cInput[i - 1][j - 1];
        }
        cText[i][j + 1] = '\0';
    }
    /*printf("\n");
    for(i = 0; i < MAX_LINES + 2; i++) printf("%s\n", cText[i]);*/

    res = 0;
    for(i = 1; i < MAX_LINES + 1; i++){
        for(j = 1; j < STR_SIZE + 1 && cText[i][j] != '\0' && cText[i][j] != '\r'; j += d == 0 ? 1: d){
            d = strToInt(cText[i], j, &n);
            check = 0;
            /*printf("(%d, %d, %c)\n", d, n, cText[i][j]);*/
            if(n > 0){
                for(k1 = i - 1; k1 <= i + 1; k1++){
                    for(k2 = j - 1; k2 <= j + d; k2++)
                        if(k1 != i || k2 == j - 1 || k2 == j + d)
                            check += (cText[k1][k2] != '.') && (cText[k1][k2] < '0' || cText[k1][k2] > '9');
                }
            }
            /*printf("> (%c, %d): %d\n", cText[i][j], n, check);*/
            if(check) res += n;
        }
    }
    
    printf("%d", res);
    
    /*--------------------------------*/

    return 0;
}
