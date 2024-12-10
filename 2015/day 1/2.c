#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1
#define STR_SIZE 7000

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, res;

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
    for(i = 0; i < STR_SIZE; i++){
        if(cInput[0][i] == '(') res++;
        else res--;
        if(res < 0) break;
    }
    res = i + 1;

    /*--------------------------------*/

    printf("%d", res);
    
    return 0;
}
