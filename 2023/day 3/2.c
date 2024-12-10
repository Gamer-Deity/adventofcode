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
    char c, cInput[MAX_LINES][STR_SIZE + 1], cText[MAX_LINES + 2][STR_SIZE + 3], cMask[MAX_LINES + 2][STR_SIZE + 3];
    long int iMask[MAX_LINES + 2][STR_SIZE + 3];
    int i, j;
    int n, d, k1, k2;
    long int res, size;
    
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
    /*for(i = 0; i < MAX_LINES; i++) printf("%s\n", cInput[i]);*/

    /*--------------------------------*/

    size = (MAX_LINES + 2) * (STR_SIZE + 3);

    for(i = 0; i < size; i++){
        iMask[0][i] = 1;
        cMask[0][i] = '\0';
        cText[0][i] = '.';
    }
    /*memset(cMask, '\0', size * sizeof(char));
    memset(cText, '.', size * sizeof(char));*/

    cText[0][STR_SIZE + 2] = '\0';
    for(i = 1; i < MAX_LINES + 1; i++){
        for(j = 1; j < STR_SIZE + 1; j++){
            cText[i][j] = cInput[i - 1][j - 1];
        }
        cText[i][j + 1] = '\0';
    }

    for(i = 1; i < MAX_LINES + 1; i++){
        for(j = 1; j < STR_SIZE + 1 && cText[i][j] != '\0' && cText[i][j] != '\r'; j += d == 0 ? 1: d){
            d = strToInt(cText[i], j, &n);

            if(n > 0){
                for(k1 = i - 1; k1 <= i + 1; k1++){
                    for(k2 = j - 1; k2 <= j + d; k2++)
                        if(cText[k1][k2] == '*'){
                            cMask[k1][k2] += 1;
                            iMask[k1][k2] *= n;
                            /*printf("(%d, %d): %d -> %ld\n", k1, k2, n, iMask[k1][k2]);*/
                        }
                }
            }
        }
    }

    res = 0;
    for(i = 1; i < size; i++)
        if(cMask[0][i] == 2)
            res += iMask[0][i];
    
    printf("%ld", res);
    
    /*--------------------------------*/

    return 0;
}
