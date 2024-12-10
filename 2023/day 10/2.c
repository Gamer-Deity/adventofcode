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

int countBorders(const char cInput[MAX_LINES][STR_SIZE + 1], int i, int j){
    int res;
    direct direction;

    res = 0;
    direction = LEFT;
    while(j > 0){
        j--;
        switch(cInput[i][j]){
            case 'J':
                direction = UP;
                res++;
                break;
            case '7':
                direction = DOWN;
                res++;
                break;
            case 'F':
                if(direction != UP) res++;
                direction = LEFT;
                break;
            case 'L':
                if(direction != DOWN) res++;
                direction = LEFT;
                break;
            case '|':
                res++;
                break;
        }
    }

    return res;
}

direct getDirection(const char cInput[MAX_LINES][STR_SIZE + 1], int i, int j, direct direction){
    switch ((cInput[i][j])){
        case 'S':
            if(cInput[i - 1][j] == '|' || cInput[i - 1][j] == 'F' || cInput[i - 1][j] == '7')
                return UP;
            if(cInput[i + 1][j] == '|' || cInput[i + 1][j] == 'F' || cInput[i + 1][j] == '7')
                return DOWN;
            return RIGHT;

        case 'L':
            if(direction == DOWN) return RIGHT;
            return UP;

        case 'J':
            if(direction == DOWN) return LEFT;
            return UP;

        case '7':
            if(direction == UP) return LEFT;
            return DOWN;

        case 'F':
            if(direction == UP) return RIGHT;
            return DOWN;  

        default:
            return direction;
    }
}

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j;
    long int res;
    char cMap[MAX_LINES][STR_SIZE + 1];
    direct direction, startingDirection;

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
    
    startingDirection =  getDirection(cInput, i, j, 0);
    direction = startingDirection;

    do{
        switch (direction){
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
        if(cInput[i][j] != 'S')
            direction =  getDirection(cInput, i, j, direction);

        cMap[i][j] = cInput[i][j];
    } while(cInput[i][j] != 'S');

    switch (direction){
        case UP:
            cMap[i][j] = '|';
            break;
        case LEFT:
            if(startingDirection == UP) cMap[i][j] = 'L';
            else cMap[i][j] = 'F';
            break;
        case RIGHT:
            switch (startingDirection){
                case UP:
                    cMap[i][j] = 'J';
                    break;
                case DOWN:
                    cMap[i][j] = '7';
                    break;
                case RIGHT:
                    cMap[i][j] = '-';
                    break;
            }
    }

    res = 0;
    for(i = 0; i < MAX_LINES; i++)
        for(j = 0; j < STR_SIZE; j++)
            if(cMap[i][j] == '.'){
                if(countBorders(cMap, i, j) % 2){
                    res++;
                    cMap[i][j] = 'I';
                }
                else cMap[i][j] = 'O';
            }

    /*--------------------------------*/

    printf("%ld", res);

    for(i = 0; i < MAX_LINES; i++)
        printf("\n%s", cMap[i]);
    
    return 0;
}
