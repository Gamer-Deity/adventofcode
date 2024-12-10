#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LISTA 5
#define SIZE_STR 5

int findNum(char cInput[])
{
	int j;
	char cAux[SIZE_STR];
	for(j = 0; j < strlen(cInput); j++)
	{
		cAux[j] = cInput[j + 1];
	}
	cAux[j] = '\0';
	return atoi(cAux);
}

int main()
{
	char cInput[MAX_LISTA][SIZE_STR] = {
		"F10",
		"N3",
		"F7",
		"R90",
		"F11"
	};
	char cAux[SIZE_STR];
	int i, j;
	int east, north;
	int facing; //0 -> east
				//1 -> north
				//2 -> west
				//3 -> south
	
	for(i = 0, east = 0, north = 0, facing = 0; i < MAX_LISTA; i++)
	{
		printf("%d\n", findNum(cInput[i]));
		switch(cInput[i][0])
		{
			case 'N':
				break;
			case 'S':
				break;
			case 'E':
				break;
			case 'W':
				break;
			case 'L':
				break;
			case 'R':
				break;
			case 'F':
				break;
		}
	}
}
