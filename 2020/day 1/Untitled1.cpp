#include <stdio.h>
#include <stdlib.h>

#define MAX_LISTA 200

int iLeArquivo(void);

int x[MAX_LISTA];// = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int main()
{
	int y, x1, x2, x3, a1, a2, a3;
	bool b;
	
	iLeArquivo();
	for(int i = 0; i < sizeof(x)/sizeof(int) - 1; i++)
	{
		for(int j = 0; j < sizeof(x)/sizeof(int) - 1; j++)
		{
			for(int k = 0; k < sizeof(x)/sizeof(int) - 1; k++)
			{
				if(i != j && j != k && i != k)
				{
					y = x[i] + x[j] + x[k];
					//printf("%d = %d + %d\n", y, x[i], x[j]);
				}
				if(y == 2020) 
				{
					a1 = i, a2 = j, a3 = k;
					x1 = x[i];
					x2 = x[j];
					x3 = x[k];
					b = true;
					break;
				}
			}
			if(b == true) break;
		}
		if(b == true) break;
	}
	
	printf("%d = %d * %d * %d	(%d, %d, %d)", x1*x2*x3, x1, x2, x3, a1, a2, a3);
	return 0;
}


int iLeArquivo(void)
{
	FILE *h;
	char szNum[12];
	int iCount = 0;
	
	h = fopen("input.txt", "rt");
	if (h == NULL) return -1;
	
	while (!feof(h) && iCount < MAX_LISTA) {
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	// szNum - > linha lida
		x[iCount++] = atoi(szNum);
   }

   fclose(h);
   return 0;
}
