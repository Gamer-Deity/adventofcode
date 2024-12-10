#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**/
#define MAX_LINES 1388
#define STR_SIZE 17
/**
#define MAX_LINES 16
#define STR_SIZE 9
/**/

int compareCol(const char cInput[MAX_LINES][STR_SIZE + 1], int col1, int col2, int start, int size){
    int i, j;

    for(i = start, j = 0; i < start + size; i++)
        if(cInput[i][col1] != cInput[i][col2])
            j++;
    
    return j;
}

int compareCols(const char cInput[MAX_LINES][STR_SIZE + 1], int i0, int size, int range){
    int i, j, isSymmetric;

    for(isSymmetric = 0, i = 1; i < range && isSymmetric != 1; i++)
        for(isSymmetric = 0, j = 1; i - j >= 0 && i + j - 1 < range && isSymmetric <= 1; j++)
            isSymmetric += compareCol(cInput, i - j, i + j - 1, i0, size);
    i--;
    j--;
    if(i > range / 2) j = range - j;

    if(isSymmetric == 1) {
        /*printf("C %d / ", j);*/
        return j;
    }
    return 0;
}

int compareRow(const char cInput[MAX_LINES][STR_SIZE + 1], int row1, int row2){
    int i, j;

    for(i = j = 0; cInput[row1][i] != '\0'; i++)
        if(cInput[row1][i] != cInput[row2][i])
            j++;

    return j;
}

int compareRows(const char cInput[MAX_LINES][STR_SIZE + 1], int i0, int size){
    int i, j, isSymmetric;

    for(isSymmetric = 0, i = 1; i < size && isSymmetric != 1; i++)
        for(isSymmetric = 0, j = 1; i - j >= 0 && i + j - 1 < size && isSymmetric <= 1; j++){
            isSymmetric += compareRow(cInput, i0 + i - j, i0 + i + j - 1);
            /*printf("(%d, %d:%d)\n", compareRow(cInput, i0 + i - j, i0 + i + j - 1), i0+i-j, i0+i+j-1);*/
        }
    i--;
    j--;
    if(i > size / 2) j = size - j;
    
    /*printf("[%d: %d]\n", i0, isSymmetric);*/
    if(isSymmetric == 1) {
        /*printf("R %d / ", j);*/
        return j;
    }
    return 0;
}

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, k, res;
    int numPatterns, *sizePatterns;

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

    for(i = numPatterns = 0; i < MAX_LINES; i++)
        if(cInput[i][0] == '\0') numPatterns++;
    sizePatterns = malloc(sizeof(int) * numPatterns);
    for(i = j = k = 0; i < MAX_LINES; i++)
        if(cInput[i][0] == '\0'){
            sizePatterns[k++] = i - j;
            j = i + 1;
        }
    
    res = 0;
    for(k = i = 0; k < numPatterns; i += sizePatterns[k] + 1, k++){
        for(j = 0; cInput[i][j] != '\0'; j++);
        res += 100 * compareRows(cInput, i, sizePatterns[k]);
        res += compareCols(cInput, i, sizePatterns[k], j);
        /*printf("%d\n\n", res);*/
    }

    /*--------------------------------*/

    printf("%d", res);

    return 0;
}
