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

int main(){
	char **cInput;
	int i, j, iOutput, aux, iFirst, iLast;
	
	iReadFile("input_day1.txt", &cInput, MAX_LINES, STR_SIZE);
	
	iOutput = 0;

	for(i = 0; i < MAX_LINES; i++){
		iFirst = iLast = -1;
		for(j = 0; cInput[i][j] != '\0'; j++){
			if(isDigit(cInput[i][j])){
				aux = toInt(cInput[i][j]);
				if(iFirst < 0) iFirst = aux;
				iLast = aux;
			}
		}
		if(iFirst >= 0) iOutput += 10 * iFirst + iLast;
	}

	printf("%d", iOutput);
	
	return 0;
}
