#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTA 1000
#define SIZE_STR 40

int iLeArquivo(void);

int main()
{
	int iCount, i, j, n = 0;
	int iPos1, iPos2;
	char c, cMin[5], cMax[5], szNum[SIZE_STR];
	FILE *h;
	
	
	h = fopen("input.txt", "rt");
	if (h == NULL) return -1;
	
	while (!feof(h) && iCount < MAX_LISTA)
	{
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	
    	
    	i = 0;
		while(szNum[i] != '-')
		{
			cMin[i] = szNum[i];
			i++;
		}
		cMin[i] = 0;
		iPos1 = atoi(cMin);
		//printf("%d ", iPos1);
		i++;
    	
    	
    	j = 0;
    	while(szNum[i] != ' ')
    	{
    		cMax[j] = szNum[i];
    		i++;
			j++;
		}
		cMax[j] = 0;
		//printf("%c  ", cMax[1]);
		iPos2 = atoi(cMax);
		//printf("%d ", iPos2);
    	
    	while(szNum[i] != ':')
    	{
    		c = szNum[i];
    		i++;
		}
		i++;
		//printf("%c ", szNum[i]);
		
		if(szNum[i + iPos1] == c)
		{
			if(szNum[i + iPos2] != c)
			{
				n++;
			}
		}
		else if(szNum[i + iPos2] == c)
		{
			n++;
		}
		iCount++;
	}

	fclose(h);
	
	printf("%d", n);
	
	return 0;
}
