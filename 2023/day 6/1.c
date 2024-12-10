#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 2
#define STR_SIZE 36

#define isDigit(c) (c >= '0' && c <= '9')

#define NUM_RACES 4

int strToInt(char *s, int i0, int *num){
    int i;
    int n;

    for(i = i0, n = 0; s[i] != '\0' && s[i] >= '0' && s[i] <= '9'; i++){
        n *= 10;
        n += (s[i] - '0');
    }

    *num = n;
    return i - i0; /* Returns the number of digits of n */
}

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, res;
    int min, max, d, aux, times[NUM_RACES], distances[NUM_RACES];
    double fmax, fmin;

    memset(cInput, '\0', MAX_LINES * (STR_SIZE + 1));
    for(i = 0; i < MAX_LINES; i++){
        scanf("%c", &c);
        for(j = 0; c != '\n' && c != '\r' && c != '\0' && j < STR_SIZE; j++){
            cInput[i][j] = c;
            scanf("%c", &c);
        }
        cInput[i][j ] = '\0';
    }

    /*--------------------------------*/

    for(i = j = 0; i < STR_SIZE && cInput[0][i] != '\0'; i += d){
        d = strToInt(cInput[0], i, &aux);
        if(d){
            times[j++] = aux;
        }
        else d = 1;
    }
    for(i = j = 0; i < STR_SIZE && cInput[1][i] != '\0'; i += d){
        d = strToInt(cInput[1], i, &aux);
        if(d){
            distances[j++] = aux;
        }
        else d = 1;
    }
    
    for(i = 0, res = 1; i < NUM_RACES; i++){
        /*printf("%d %d\n", times[i], distances[i]);*/
        fmax = (times[i] + sqrt(times[i] * times[i] - 4 * distances[i])) * 0.5f;
        fmin = (times[i] - sqrt(times[i] * times[i] - 4 * distances[i])) * 0.5f;
        max = (double)(int)fmax == fmax ? (int)(fmax - 1) : (int)(fmax);
        min = (int)(fmin + 1);
        /*printf("(%lf, %lf) - (%d, %d)\n", fmax, fmin, max, min);
        printf("%d\n", max - min + 1);*/
        res *= max - min + 1;
    }

    /*--------------------------------*/

    printf("%d", res);
    
    return 0;
}
