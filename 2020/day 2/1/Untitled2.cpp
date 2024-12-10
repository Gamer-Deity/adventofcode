#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTA 1000
#define SIZE_STR 40

int iLeArquivo(void);

char texto[MAX_LISTA][SIZE_STR];

int main()
{
	int i, j = 0;
	char cMin[5], cMax[5];
	int iMin, iMax;
	
	iLeArquivo();
	
	for(i = 0; i < MAX_LISTA; i++)
	{
		/*j = 0;
		while(j < 3)
		{
			cMin[j] = texto[i][j];
			j++;
		}
		cMin[j] = 0;
		iMin = atoi(cMin);
		printf("%d ", iMin);*/
		
		j = 0;
		while(texto[i][j] != '-')
		{
			cMin[j] = texto[i][j];
			j++;
		}
		cMin[j] = 0;
		iMin = atoi(cMin);
		printf("%d ", iMin);
	}
	
	return 0;
}

int iLeArquivo(void)
{
	FILE *h;
	char szNum[SIZE_STR];
	int iCount = 0;
	
	h = fopen("input.txt", "rt");
	if (h == NULL) return -1;
	
	while (!feof(h) && iCount < MAX_LISTA) {
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	// szNum - > linha lida
    	
    	strcpy(texto[iCount], szNum);
    	
    	/*for(int i = 0; i < SIZE_STR; i++)
    	{
    		texto[iCount][i] = szNum[i];
		}*/
		iCount++;
		//printf("%c", texto[0][0]);
   }

   fclose(h);
   return 0;
}
