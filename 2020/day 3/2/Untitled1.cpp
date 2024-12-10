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
		if(strlen(szNum) < MAP_WIDHT) break;
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
	long long int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
	
	iLeArquivo();
	//for(int k = 0; k < 1000; k++) printf("\n%d:%d|", k, map[0][k]);
	
	for(int i = 0, j = 0; i < MAP_HEIGHT; i++, j++)
	{
		if(map[i][j % (MAP_WIDHT)] == '#')
		{
			n1++;
		}
	}
	
	for(int i = 0, j = 0; i < MAP_HEIGHT; i++, j += 3)
	{
		if(map[i][j % (MAP_WIDHT)] == '#')
		{
			n2++;
		}
	}
	
	for(int i = 0, j = 0; i < MAP_HEIGHT; i++, j += 5)
	{
		if(map[i][j % (MAP_WIDHT)] == '#')
		{
			n3++;
		}
	}
	
	for(int i = 0, j = 0; i < MAP_HEIGHT; i ++, j += 7)
	{
		if(map[i][j % (MAP_WIDHT)] == '#')
		{
			n4++;
		}
	}
	
	for(int i = 0, j = 0; i < MAP_HEIGHT; i += 2, j++)
	{
		if(map[i][j % (MAP_WIDHT)] == '#')
		{
			n5++;
		}
	}
	//printf("\n\n%s%s", map[1], map[2]);
	printf("\n\n\n%d * %d * %d * %d * %d = %lld", n1, n2, n3, n4, n5, n1*n2*n3*n4*n5);
	
	return 0;
}
