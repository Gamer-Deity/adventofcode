#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
#define MAX_LINES 110
#define STR_SIZE 110
/**/
#define MAX_LINES 10
#define STR_SIZE 10
/**/

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

    
    
    /*--------------------------------*/

    return 0;
}
