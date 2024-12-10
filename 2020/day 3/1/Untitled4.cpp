#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_WIDHT 31
#define MAP_HEIGHT 323

char map[MAP_HEIGHT][MAP_WIDHT];

int iLeArquivo(void)
{
	FILE *h;
	char szNum[MAP_WIDHT + 5];
	int iCount = 0;
	
	h = fopen("input.txt", "rt");
	if (h == NULL) return -1;
	
	while (!feof(h) && iCount < MAP_HEIGHT) {
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	// szNum - > linha lida
    	
    	for(int i = 0; i < MAP_WIDHT; i++)
    	{
    		map[iCount][i] = szNum[i];
    		printf("%c", map[iCount][i]);
		}
		printf("\n");
		iCount++;
		//printf("%c", texto[0][0]);
   }

   fclose(h);
   return 0;
}


int main()
{
	int n = 0, a;
	
	iLeArquivo();
	//for(int k = 0; k < 10657; k++) printf("\n%d: %c", k, map[0][k]);
	
	for(int i = 0, j = 0; i < MAP_HEIGHT; i++, j += 3)
	{
		//if(j > MAP_WIDHT - 3) j = j - (MAP_WIDHT - 3);
		//printf("%d", i);
		//printf("%c", map[i][j]);
		if(map[i][j % (MAP_WIDHT)] == '#') //if(map[i][j % ] == '#')
		{
			n++;
		}
		a = i;
	}
	printf("\n\n%d\n--%d--", a, n);
	
	/*
	while(map[0][j] != '\0')
	{
		printf("%c", map[0][j]);
		n++;
		j++;
	}
	printf("%d", n);
	*/
	
	return 0;
}
