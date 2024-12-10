#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**/
#define MAX_LINES 140
#define STR_SIZE 140
/**
#define MAX_LINES 10
#define STR_SIZE 10
/**/

#define EXPANSION_SIZE (1000000 - 1)

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a < 0 ? -(a) : a)

typedef struct{
    int x;
    int y;
} coord;

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, k;
    long int res;
    int *spaceCol, sizeSpaceCol, *spaceRow, sizeSpaceRow, lineNull, numGalaxies;
    coord *galaxies;

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

    for(i = sizeSpaceRow = 0; i < MAX_LINES; i++){
        lineNull = 1;
        for(j = 0; j < STR_SIZE && lineNull; j++)
            if(cInput[i][j] != '.') lineNull = 0;
        if(lineNull) sizeSpaceRow++;
    }
    spaceRow = (int*)malloc(sizeof(int) * sizeSpaceRow);
    if(!spaceRow) return 1;
    for(i = k = 0; i < MAX_LINES; i++){
        lineNull = 1;
        for(j = 0; j < STR_SIZE && lineNull; j++)
            if(cInput[i][j] != '.') lineNull = 0;
        if(lineNull) spaceRow[k++] = i;
    }

    for(i = sizeSpaceCol = 0; i < MAX_LINES; i++){
        lineNull = 1;
        for(j = 0; j < STR_SIZE && lineNull; j++)
            if(cInput[j][i] != '.') lineNull = 0;
        if(lineNull) sizeSpaceCol++;
    }
    spaceCol = (int*)malloc(sizeof(int) * sizeSpaceCol);
    if(!spaceCol) return 1;
    for(i = k = 0; i < MAX_LINES; i++){
        lineNull = 1;
        for(j = 0; j < STR_SIZE && lineNull; j++)
            if(cInput[j][i] != '.') lineNull = 0;
        if(lineNull) spaceCol[k++] = i;
    }

    /*for(i = 0; i < sizeSpaceCol; i++) printf("%d ", spaceCol[i]);
    printf("\n");
    for(i = 0; i < sizeSpaceRow; i++) printf("%d ", spaceRow[i]);*/

    for(i = numGalaxies = 0; i < MAX_LINES; i++)
        for(j = 0; j < STR_SIZE; j++)
            if(cInput[i][j] == '#') numGalaxies++;
    galaxies = (coord*)malloc(sizeof(coord) * numGalaxies);
    if(!galaxies) return 1;
    for(i = k = 0; i < MAX_LINES; i++)
        for(j = 0; j < STR_SIZE; j++)
            if(cInput[i][j] == '#'){
                galaxies[k].x = j;
                galaxies[k].y = i;
                k++;
            }

    res = 0;
    for(i = 0; i < numGalaxies - 1; i++){
        for(j = i + 1; j < numGalaxies; j++){
            if(i != j){
                for(k = 0; k < sizeSpaceCol; k++)
                    if(spaceCol[k] < max(galaxies[i].x, galaxies[j].x) && spaceCol[k] > min(galaxies[i].x, galaxies[j].x))
                        res += EXPANSION_SIZE;
                for(k = 0; k < sizeSpaceRow; k++)
                    if(spaceRow[k] < max(galaxies[i].y, galaxies[j].y) && spaceRow[k] > min(galaxies[i].y, galaxies[j].y))
                        res += EXPANSION_SIZE;
                /*printf("%d %d\n", abs(galaxies[i].x - galaxies[j].x), abs(galaxies[i].y - galaxies[j].y));*/
                res += abs(galaxies[i].x - galaxies[j].x) + abs(galaxies[i].y - galaxies[j].y);
            }
        }
    }

    free(spaceCol);
    free(spaceRow);
    free(galaxies);

    /*--------------------------------*/

    printf("%ld", res);
    
    return 0;
}
