#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1
/**/
#define STR_SIZE 22902
/**
#define STR_SIZE 52
/**/

#define lable_STR_SIZE 15
#define HASH(c, h) ((((int)c + h) * 17) % 256)

typedef struct _lable{
    struct _lable *prev;
    struct _lable *next;
    char *lableStr;
    int val;
} lable;

typedef struct{
    lable *lables;
    int length;
} box;

void append(box *pBox, const char *s, int val){
    int size;
    lable *currentLable;

    for(size = 0; s[size] != '\0'; size++);

    currentLable = pBox->lables;
    if(currentLable != NULL){
        while(currentLable->next != NULL)
            currentLable = currentLable->next;
        
        currentLable->next = (lable*)malloc(sizeof(lable));
        currentLable->next->prev = currentLable;
        currentLable = currentLable->next;
    }
    else{
        pBox->lables = (lable*)malloc(sizeof(lable));
        currentLable = pBox->lables;
        currentLable->prev = NULL;
    }

    currentLable->lableStr = (char*)malloc(sizeof(char*) * size);
    strcpy(currentLable->lableStr, s);
    currentLable->val = val;
    currentLable->next = NULL;
}

lable* find(box *pBox, const char *s){
    lable *currentLable;

    currentLable = pBox->lables;
    while(currentLable != NULL && strcmp(currentLable->lableStr, s))
        currentLable = currentLable->next;
    
    return currentLable;
}

void set(lable *l, int val){
    l->val = val;
}

void deletelable(lable *l){
    free(l->lableStr);
    /*printf("2[%s %d %d %d]\n", l->lableStr, l->next, l->prev, l->val);*/
    free(l);
}

void deleteBox(box *pBox){
    lable *currentLable;

    currentLable = pBox->lables;
    while(currentLable->next != NULL){
        currentLable = currentLable->next;
        deletelable(currentLable->prev);
    }
    if(currentLable != NULL) deletelable(currentLable);
}

void pop(box *pBox, lable *l){
    /*printf("1[%s %d %d](%s) \n", l->lableStr, l->next, l->prev, l->next ? l->next->lableStr : 0);*/
    if(l->next) l->next->prev = l->prev;
    if(l->prev) l->prev->next = l->next;
    else pBox->lables = l->next;
    l->prev = l->next = NULL;
    /*deletelable(l);*/
}

int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, res;
    int hash;
    char currentLableStr[lable_STR_SIZE];
    lable *currentLable;
    box boxes[256];

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

    memset(currentLableStr, '\0', lable_STR_SIZE);
    for(i = 0; i < 256; i++) boxes[i].lables = NULL;
    for(i = j = hash = 0; i < STR_SIZE; i++){
        switch(cInput[0][i]){
            case '-':
                /*printf("- %s %d\n", currentLableStr, hash);*/
                currentLable = find(&boxes[hash], currentLableStr);
                if(currentLable) pop(&boxes[hash], currentLable);
                i++;
                memset(currentLableStr, '\0', lable_STR_SIZE);
                j = hash = 0;
                break;
            
            case '=':
                /*printf("= %s %d %d %d\n", currentLableStr, hash, cInput[0][i + 1] - '0', find(&boxes[hash], currentLableStr));*/
                currentLable = find(&boxes[hash], currentLableStr);
                if(currentLable) set(currentLable, cInput[0][++i] - '0');
                else append(&boxes[hash], currentLableStr, cInput[0][++i] - '0');
                i++;
                memset(currentLableStr, '\0', lable_STR_SIZE);
                j = hash = 0;
                break;

            default:
                hash = HASH(cInput[0][i], hash);
                currentLableStr[j++] = cInput[0][i];
                break;
        }
    }

    res = 0;
    for(i = 0; i < 256;){
        currentLable = boxes[i].lables;
        j = 1;
        i++;
        while(currentLable){
            /*printf("{%d}", currentLable->next);
            printf("%d: [%s %d]\n", i, currentLable->lableStr, currentLable->val);*/
            res += i * j * (currentLable->val);
            currentLable = currentLable->next;
            j++;
        }
    }

    /*for(i = 0; i < 256; i++) deleteBox(&boxes[i]);*/

    /*--------------------------------*/

    printf("%d", res);

    return 0;
}
