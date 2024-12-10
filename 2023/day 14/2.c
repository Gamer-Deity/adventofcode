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
    unsigned int l;

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

    for(l = 0; l < 100; l++){
        for(k = MAX_LINES; k > 1; k--)
            for(i = 1; i < k; i++)
                for(j = 0; j < STR_SIZE; j++)
                    if(cInput[i][j] == 'O' && cInput[i - 1][j] == '.'){
                        cInput[i][j] = '.';
                        cInput[i - 1][j] = 'O';
                    }
        for(k = STR_SIZE; k > 1; k--)
            for(j = 1; j < k; j++)
                for(i = 0; i < MAX_LINES; i++)
                    if(cInput[i][j] == 'O' && cInput[i][j - 1] == '.'){
                        cInput[i][j] = '.';
                        cInput[i][j - 1] = 'O';
                    }
        for(k = 0; k <= MAX_LINES - 2; k++)
            for(i = MAX_LINES - 2; i >= k; i--)
                for(j = 0; j < STR_SIZE; j++)
                    if(cInput[i][j] == 'O' && cInput[i + 1][j] == '.'){
                        cInput[i][j] = '.';
                        cInput[i + 1][j] = 'O';
                    }
        for(k = 0; k <= STR_SIZE - 2; k++)
            for(j = STR_SIZE - 2; j >= k; j--)
                for(i = 0; i < MAX_LINES; i++)
                    if(cInput[i][j] == 'O' && cInput[i][j + 1] == '.'){
                        cInput[i][j] = '.';
                        cInput[i][j + 1] = 'O';
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
        printf("\n\n");
    }

    

    return 0;
}
