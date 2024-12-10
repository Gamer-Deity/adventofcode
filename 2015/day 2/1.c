#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define STR_SIZE 8

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
    int i, j, k, res;
    int dim[3], min, aux;

    memset(cInput, '\0', MAX_LINES * (STR_SIZE + 1));
    for(i = 0; i < MAX_LINES; i++){
        scanf("%c", &c);
        for(j = 0; c != '\n' && c != '\r' && c != '\0' && j < STR_SIZE; j++){
            cInput[i][j] = c;
            scanf("%c", &c);
        }
        cInput[i][j] = '\0';
    }

    /*--------------------------------*/

    res = 0;
    for(i = 0; i < MAX_LINES; i++){
        for(j = k = 0; j < STR_SIZE && cInput[i][j] != '\0';)
            j += strToInt(cInput[i], j, &dim[k++]) + 1;
        min = -1;
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                if(j != k){
                    aux = dim[j] * dim[k];
                    if(aux < min || min < 0) min = aux;
                    res += aux;
                }
            }
        }
        res += min;
    }

    /*--------------------------------*/

    printf("%d", res);
    
    return 0;
}
