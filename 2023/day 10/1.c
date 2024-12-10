#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 140
#define STR_SIZE 140

typedef enum {
    UP,
    DOWN,
    RIGHT,
    LEFT
} direct;

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j;
    long int res;
    char cMap[MAX_LINES][STR_SIZE + 1];
    direct direction;

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
        for(j = 0; j < STR_SIZE && cInput[i][j] != '\0'; j++)
            cMap[i][j] = '.';
        cMap[i][j] = '\0';
    }

    i = -1;
    while (cInput[i][j] != 'S'){
        i++;
        for(j = 0; j < STR_SIZE && cInput[i][j] != '\0' && cInput[i][j] != 'S'; j++);
    }
    
    if(cInput[i - 1][j] == '|' || cInput[i - 1][j] == 'F' || cInput[i - 1][j] == '7')
        direction = UP;
    else if(cInput[i + 1][j] == '|' || cInput[i + 1][j] == 'F' || cInput[i + 1][j] == '7')
        direction = DOWN;
    else direction = RIGHT;

    do{
        switch (direction)
        {
            case UP:
                i--;
                break;

            case DOWN:
                i++;
                break;

            case RIGHT:
                j++;
                break;

            case LEFT:
                j--;
                break;
        }

        switch ((cInput[i][j]))
        {
            case 'L':
                if(direction == DOWN) direction = RIGHT;
                else direction = UP;
                break;

            case 'J':
                if(direction == DOWN) direction = LEFT;
                else direction = UP;
                break;

            case '7':
                if(direction == UP) direction = LEFT;
                else direction = DOWN;
                break;

            case 'F':
                if(direction == UP) direction = RIGHT;
                else direction = DOWN;  
                break;
        }

        res++;
        cMap[i][j] = cInput[i][j];
        /*printf("%d, (%d, %d), %c\n", direction, i, j, cInput[i][j]);*/
    } while(cInput[i][j] != 'S');

    res /= 2;

    /*--------------------------------*/

    printf("%ld", res);

    for(i = 0; i < MAX_LINES; i++)
        printf("\n%s", cMap[i]);
    
    return 0;
}
