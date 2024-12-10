#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 221
#define STR_SIZE 204
/*
#define MAX_LINES 34
#define STR_SIZE 28
*/

#define isDigit(c) (c >= '0' && c <= '9')

typedef struct{
    long int **p;
    int size;
} convertStruct;

long int convertSeed(long int num, long int destStart, long int sourceStart, long int range){
    if(num < sourceStart + range && num >= sourceStart) return destStart + num - sourceStart;
    return num;
}

int strToLongInt(char *s, int i0, long int *num){
    int i;
    long int n;

    for(i = i0, n = 0; s[i] != '\0' && s[i] >= '0' && s[i] <= '9'; i++){
        n *= 10;
        n += (s[i] - '0');
    }

    *num = n;
    return i - i0; /* Returns the number of digits of n */
}

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, k;
    int aux1, aux3;
    long int aux2, l, res;
    int size, numSeeds;
    long int **seeds;
    convertStruct convert[7];

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

    for(i = 6; i < STR_SIZE && cInput[0][i] != '\0'; i++)
        if(cInput[0][i] == ' ') numSeeds++;
    numSeeds /= 2;
    seeds = malloc(sizeof(long int*) * numSeeds);
    for(i = 0; i < numSeeds; i++) seeds[i] = malloc(sizeof(long int) * 2);
    for(i = 7, j = k = 0; i < STR_SIZE && cInput[0][i] != '\0';){
        i += 1 + strToLongInt(cInput[0], i, &seeds[j][k%2]);
        j += k%2;
        k++;
    }
    /*for(i = 0; i < numSeeds; i++)
        printf("%ld, %ld\n", seeds[i][0], seeds[i][1]);*/

    for(i = 3, j = size = 0; i + size <= MAX_LINES;){
        if(!isDigit(cInput[i + size][0])){
            convert[j].p = malloc(sizeof(int*) * size);
            for(k = i; k < i + size; k++){
                convert[j].p[k - i] = malloc(sizeof(int) * 3);
                for(l = aux3 = 0; cInput[k][l] != '\0';){
                    aux1 = strToLongInt(cInput[k], l, &aux2);
                    if(aux1){
                        convert[j].p[k - i][aux3++] = aux2;
                        l += aux1;
                    }
                    else l += 1;
                }
            }
            convert[j].size = size;
            i += size + 2;
            j++;
            size = 0;
        }
        else size++;
    }

    for(i = 0, res = -1; i < numSeeds; i++){
        for(l = seeds[i][0]; l < seeds[i][0] + seeds[i][1]; l++){
            /*printf("%ld -> ", l);*/
            aux2 = l;
            for(j = 0; j < 7; j++){
                k = 0;
                while(k < convert[j].size && (aux2 >= convert[j].p[k][1] + convert[j].p[k][2] || aux2 < convert[j].p[k][1]))
                    k++;
                if(k == convert[j].size) k--;
                aux2 = convertSeed(aux2, convert[j].p[k][0], convert[j].p[k][1], convert[j].p[k][2]);
            }
            /*printf("%ld\n", aux2);*/
            if(res < 0 || aux2 < res) {
                /*printf("[%ld, %ld]\n", res, aux2);*/
                res = aux2;
            }
        }
        /*printf("\n");*/
    }

    for(i = 0; i < numSeeds; i++)
        free(seeds[i]);
    free(seeds);
    for(i = 0; i < 7; i++){
        for(j = 0; j < convert[i].size; j++)
            free(convert[i].p[j]);
        free(convert[i].p);
    }

    /*--------------------------------*/
                
    printf("%ld", res);
    
    return 0;
}
