#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTA 30
#define SIZE_STR 30

char c[MAX_LISTA][SIZE_STR];

int iLeArquivo(void)
{
	FILE *h;
	char szNum[SIZE_STR];
	int iCount = 0;
	
	h = fopen("input2.txt", "rt");
	if (h == NULL) return -1;
	
	while (!feof(h) && iCount < MAX_LISTA) {
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	// szNum - > linha lida
		strcpy(c[iCount], szNum);
		printf("%s", c[iCount]);
		iCount++;
   }

   fclose(h);
   return 0;
}

int main()
{
	iLeArquivo();
}
