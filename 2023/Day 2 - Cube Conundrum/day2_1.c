#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define STR_SIZE 200
#define N_R 12
#define N_G 13
#define N_B 14

typedef enum{
    RED,
    GREEN,
    BLUE
} eColor;

int strComp(char *s0, char *s, int i0){
    int i, di;

    for(di = 0; s[di] != '\0'; di++);
    for(i = 0; i < di; i++){
        if(s0[i + i0] != s[i]) return 0;
    }
    return 1;
}

int findColor(char *s, int i0, eColor *color){
    if(strComp(s, "red", i0)){
        *color = RED;
        return 3;
    }
    if(strComp(s, "green", i0)){
        *color = GREEN;
        return 5;
    }
    if(strComp(s, "blue", i0)){
        *color = BLUE;
        return 4;
    }
    return 0;
}

int strToInt(char *s, int i0, int *num){
    int i, n;

    for(i = i0, n = 0; s[i] != '\0' && s[i] >= '0' && s[i] <= '9'; i++){
        n *= 10;
        n += (s[i] - '0');
        /*printf("[%c, %d, %d] ", s[i], i, n);*/
    }
    /*printf("{%d} -> %d, %d : %c\n", __LINE__, n, i0, s[i0]);*/

    *num = n;
    return i - i0 - 1; /* Returns the number of digits of n */
}

int numberCheck(int nColors[]){
    return nColors[0] <= N_R && nColors[1] <= N_G && nColors[2] <= N_B;
}

int main(){
    char c, cText[MAX_LINES][STR_SIZE];
    int i, j;
    int res, index, n, check;
    int nColors[3];
    eColor color;

    for(i = 0; i < MAX_LINES; i++){
        memset(cText[i], 0, STR_SIZE);

        scanf("%c", &c);
        for(j = 0; c != '\n' && j < STR_SIZE; j++){
            cText[i][j] = c;
            scanf("%c", &c);
        }
        cText[i][j] = '\0';
    }

    /*--------------------------------*/

    res = 0;
    for(i = 0; i < MAX_LINES; i++){
        memset(nColors, 0, 3 * sizeof(int));

        check = 1;
        
        /*printf("<%d> -> %d : %c >> ( %s )\n", __LINE__, i+1, cText[i][5], cText[i]);*/

        j = 6 + strToInt(cText[i], 5, &index);
        while(cText[i][j] != '\0' && cText[i][j] != '\n' && cText[i][j] != '\r' && check){

            j += 2;
            j += strToInt(cText[i], j, &n) + 2;
            j += findColor(cText[i], j, &color);

            nColors[color] = n;
            check = numberCheck(nColors);
        }
        /*printf("> %d: %d - %d\n", i + 1, check, index);*/

        if(check) res += index;
    }

    printf("%d", res);

    /*--------------------------------*/

    return 0;
 }
 