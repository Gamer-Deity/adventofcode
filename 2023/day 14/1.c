#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**/
#define MAX_LINES 100
#define STR_SIZE 100
/**
#define MAX_LINES 10
#define STR_SIZE 10
/**/

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, k, res;

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

    for(k = MAX_LINES; k >= 1; k--)
        for(i = 1; i < k; i++)
            for(j = 0; j < STR_SIZE; j++)
                if(cInput[i][j] == 'O' && cInput[i - 1][j] == '.'){
                    cInput[i][j] = '.';
                    cInput[i - 1][j] = 'O';
                }

    res = 0;
    for(i = 0; i < MAX_LINES; i++)
        for(j = 0; j < STR_SIZE; j++)
            res += (MAX_LINES - i) * (cInput[i][j] == 'O');

    /*--------------------------------*/

    printf("%d", res);

    for(i = 0; i < MAX_LINES; i++){
        printf("\n");
        for(j = 0; j < STR_SIZE; j++)
            printf("%c", cInput[i][j]);
    }

    return 0;
}
