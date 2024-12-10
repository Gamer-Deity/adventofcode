#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LISTA 5
#define SIZE_STR 5
#define DIREC_NUM 4

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
	char cAux[SIZE_STR], sFacing[6];
	int i, j, k;
	int east, north;
	int facing; //0 -> east
				//1 -> north
				//2 -> west
				//3 -> south
	
	for(i = 0, east = 0, north = 0, facing = 0; i < MAX_LISTA; i++)
	{
		k = findNum(cInput[i]);
		
		switch(cInput[i][0])
		{
			case 'N':
				north += k;
				break;
			case 'S':
				north -= k;
				break;
			case 'E':
				east += k;
				break;
			case 'W':
				east -= k;
				break;
			case 'L':
				switch(k)
				{
					case 90:
						facing += 1;
						break;
					case 180:
						facing += 2;
						break;
					case 270:
						facing += 3 ;
						break;
				}
				facing %= DIREC_NUM;
				break;
			case 'R':
				switch(k)
				{
					case 90:
						facing -= 1;
						break;
					case 180:
						facing -= 2;
						break;
					case 270:
						facing -= 3;
						break;
				}
				if(facing < 0) facing = DIREC_NUM + facing;
				break;
			case 'F':
				switch(facing)
				{
					case 0:
						east += k;
						break;
					case 1:
						north += k;
						break;
					case 2:
						east -= k;
						break;
					case 3:
						north -= k;
						break;
				}
				break;
		}
		strcpy(sFacing, facing == 0 ? "east" : (facing == 1 ? "north" : (facing == 2 ? "west" : "south")));
		if(north < 0) north *= -1;
		if(east < 0 ) east *= -1;
		printf("%s - %d - facing: %s(%d) - %s: %d - %s:%d \n", cInput[i], k, sFacing, facing, north >= 0 ? "north" : "south", north, east >= 0 ? "east" : "west", east);
	}
	
	printf("\n\n%d + %d = %d", east, north, east + north);
}
