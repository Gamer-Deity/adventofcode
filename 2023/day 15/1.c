#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1
/**/
#define STR_SIZE 22902
/**
#define STR_SIZE 52
/**/

#define HASH(c, h) ((((int)c + h) * 17) % 256)

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, res;
    int hash;

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

    /*--------------------------------*/

    for(i = hash = 0; i < STR_SIZE; i++){
        if(cInput[0][i] != ','){
            /*printf("(%c, %d) ", cInput[0][i], HASH(cInput[0][i], hash));*/
            hash = HASH(cInput[0][i], hash);
        }
        else{
            /*printf("\n");*/
            res += hash;
            hash = 0;
        }
    }

    /*--------------------------------*/

    printf("%d", res);

    return 0;
}
