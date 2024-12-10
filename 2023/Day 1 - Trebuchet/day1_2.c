#include "iReadFile.h"

#define MAX_LINES 1000
#define STR_SIZE 100

int isDigit(char c){
	if(c >= '0' && c <= '9') return 1;
	return 0;
}

int toInt(char c){
	return c - '0';
}

int strComp(char *s0, char *s, int i0){
    int i, di;

    for(di = 0; s[di] != '\0'; di++);
    for(i = 0; i < di; i++){
        if(s0[i + i0] != s[i]) return 0;
    }
    return 1;
}

int findDigit(char *s, int i0, int *delta){
    *delta = 1;
    if(isDigit(s[i0])) return toInt(s[i0]);
    if(strComp(s, "one", i0)){
        /**delta = 3;*/
        return 1;
    }
    if(strComp(s, "two", i0)){
        /**delta = 3;*/
        return 2;
    }
    if(strComp(s, "three", i0)){
        /**delta = 5;*/
        return 3;
    }
    if(strComp(s, "four", i0)){
        /**delta = 4;*/
        return 4;
    }
    if(strComp(s, "five", i0)){
        /**delta = 4;*/
        return 5;
    }
    if(strComp(s, "six", i0)){
        /**delta = 3;*/
        return 6;
    }
    if(strComp(s, "seven", i0)){
        /**delta = 5;*/
        return 7;
    }
    if(strComp(s, "eight", i0)){
        /**delta = 5;*/
        return 8;
    }
    if(strComp(s, "nine", i0)){
        /**delta = 4;*/
        return 9;
    }
    return 0;
}

int main(){
	char **cInput;
	int i, j, delta, iOutput, aux, iFirst, iLast;

	iReadFile("input_day1.txt", &cInput, MAX_LINES, STR_SIZE);
	iOutput = 0;

	for(i = 0; i < MAX_LINES; i++){
        iFirst = iLast = -1;
		for(j = 0; cInput[i][j] != '\0'; j += delta){
            aux = findDigit(cInput[i], j, &delta);
            /*printf("aux: %d\n(i, j): (%d, %d)\ncInput[i][j]: %c\ndelta: %d\n\n", aux, i, j, cInput[i][j], delta);*/
            if(aux != 0){
				if(iFirst < 0) iFirst = aux;
				iLast = aux;
			}
		}
        /*printf("[%d: (%d, %d)]\n", i + 1, iFirst, iLast);*/
		if(iFirst >= 0) iOutput += 10 * iFirst + iLast;
	}

	printf("%d", iOutput);
	
	return 0;
}
