#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**/
#define MAX_LINES 200
#define STR_SIZE 130
#define LINE_SIZE 21
/**
#define MAX_LINES 3
#define STR_SIZE 17
#define LINE_SIZE 6
/**/

int evaluateLine(int *p, int size){
    int i, all0, *diffs;

    for(i = 0, all0 = 1; i < size; i++) if(p[i]) all0 = 0;
    if(all0) return 0;

    diffs = (int*)malloc(sizeof(int) * size);

    for(i = 0; i < size - 1; i++)
        diffs[i] = p[i + 1] - p[i];
    p[size] = p[size - 1] + evaluateLine(diffs, size - 1);

    free(diffs);
    return p[size];
}

void printLine(int *p, int size){
    int i;

    for(i = 0; i < size; i++)
        printf("%d ", p[i]);
}

void printLines(int *p, int size){
    int i;

    for(i = 0; i < MAX_LINES; i++){
        printLine(&p[i * size], size);
        printf("\n");
    }
}

int strToInt(char *s, int i0, int *num){
    int i, n, sign;

    i = i0;
    if(s[i0] == '-'){
        sign = -1;
        i++;
    }
    else sign = 1;

    for(n = 0; s[i] != '\0' && s[i] >= '0' && s[i] <= '9'; i++){
        n *= 10;
        n += (s[i] - '0');
    }

    *num = n * sign;
    return i - i0; /* Returns the number of digits of n */
}

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, k;
    long int res;
    int d, aux, iInput[MAX_LINES * (LINE_SIZE + 1)];

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

    for(i = 0; i < MAX_LINES; i++){
        for(j = k = 0; j < STR_SIZE && cInput[i][j] != '\0'; j += d){
            d = strToInt(cInput[i], j, &aux);
            if(!d) d = 1;
            else iInput[i * (LINE_SIZE + 1) + k++] = aux;
        }
        iInput[i * (LINE_SIZE + 1) + k] = -1;
    }

    /*printLines(iInput, LINE_SIZE + 1);*/
    for(i = 0, res = 0; i < MAX_LINES; i++)
        res += (long int)evaluateLine(&iInput[i * (LINE_SIZE + 1)], LINE_SIZE);

    /*--------------------------------*/

    printf("%ld", res);
    
    return 0;
}
