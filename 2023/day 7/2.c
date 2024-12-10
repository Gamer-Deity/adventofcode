#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 1000
#define STR_SIZE 10

#define isDigit(c) (c >= '0' && c <= '9')

typedef enum{
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    FIVE_OF_A_KIND
} handType;

typedef struct{
    int hand[13];
    int cards[5];
    handType type;
    int bid;
} handStruct;

int suitToInt(char c){
    switch(c){
        case 'A':
            return 12;
        case 'K':
            return 11;
        case 'Q':
            return 10;
        case 'J':
            return 0;
        case 'T':
            return 9;
        default:
            return c - '2' + 1;
    }
}

handType findHandType(int *numCards, int numJ){
    handType type;

    switch(numJ){
        case 0:{
            if(numCards[5]) type = FIVE_OF_A_KIND;
            else if(numCards[4]) type = FOUR_OF_A_KIND;
            else if(numCards[3]){
                if(numCards[2]) type = FULL_HOUSE;
                else type = THREE_OF_A_KIND;
            }
            else if(numCards[2] == 2) type = TWO_PAIR;
            else if(!numCards[2]) type = HIGH_CARD;
            else type = ONE_PAIR;
        } break;

        case 1:{
            if(numCards[4]) type = FIVE_OF_A_KIND;
            else if(numCards[3]) type = FOUR_OF_A_KIND;
            else if(numCards[2] == 2) type = FULL_HOUSE;
            else if(!numCards[2]) type = ONE_PAIR;
            else type = THREE_OF_A_KIND;
        } break;

        case 2: {
            if(numCards[3]) type = FIVE_OF_A_KIND;
            else if(numCards[2] == 2) type = FOUR_OF_A_KIND;
            else type = THREE_OF_A_KIND;
        } break;

        case 3:{
            if(numCards[2]) type = FIVE_OF_A_KIND;
            else type = FOUR_OF_A_KIND;
        } break;

        case 4:
        case 5:{
            type = FIVE_OF_A_KIND;
        }
    }

    return type;
}

int compHands(handStruct *hand1, handStruct *hand2){
    int i;

    if(hand1->type > hand2->type) return 1;
    if(hand2->type > hand1->type) return 0;

    i = 0;
    while(hand1->cards[i] == hand2->cards[i])
        i++;
    return hand1->cards[i] > hand2->cards[i];
}

void sort(handStruct **p){
    int i, j;
    handStruct *aux;

    for(i = MAX_LINES - 1; i > 0 - 1; i--){
        for(j = 0; j < i; j++){
            if(compHands(p[j], p[j + 1])){
                aux = p[j];
                p[j] = p[j + 1];
                p[j + 1] = aux;
            }
        }
    }
}

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
    int suit, numCards[6];
    handStruct hands[MAX_LINES], *phands[MAX_LINES];

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

    memset(hands, 0, MAX_LINES * sizeof(handStruct));
    for(i = 0; i < MAX_LINES; i++){
        for(j = 0; j < 5; j++){
            suit = suitToInt(cInput[i][j]);
            hands[i].hand[suit]++;
            hands[i].cards[j] = suit;
        }
        j++;
        strToInt(cInput[i], j, &hands[i].bid);
    }

    for(i = 0; i < MAX_LINES; i++){
        for(j = 0; j < 6; j++) 
            numCards[j] = 0;
        for(j = 0; j < 13; j++)
            numCards[hands[i].hand[j]]++;
        hands[i].type = findHandType(numCards, hands[i].hand[0]);
    }

    for(i = 0; i < MAX_LINES; i++) phands[i] = &hands[i];
    sort(phands);

    for(i = res = 0; i < MAX_LINES; i++){
        /*for(j = 0; j < 5; j++) printf("%d ", phands[i]->cards[j]);
        printf(" - %d [%d]\n", phands[i]->bid, phands[i]->type);*/
        res += phands[i]->bid * (i + 1);
    }

    /*--------------------------------*/

    printf("%d", res);
    
    return 0;
}
