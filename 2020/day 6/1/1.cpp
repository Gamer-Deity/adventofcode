#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STR 26
#define MAX_LISTA 2120

int main(void)
{
	FILE *h;
	char szNum[SIZE_STR + 5], answers[27];
	int iCount = 0, n = 0, k = 0, i, j;
	
	h = fopen("input.txt", "rt"); //fopen("input2.txt", "rt");
	if (h == NULL)
	{
		printf("File not found.");
		return -1;
	}
	
	memset(answers, 0, sizeof(answers));
	//printf("%d", strlen(answers));
	while (!feof(h) && iCount < MAX_LISTA) {
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	// szNum - > linha lida
    	printf("%s", szNum);		

		if(szNum[0] <= ' ')
		{
			n += strlen(answers);
			printf("(n = %d)\n\n", n);
			memset(answers, 0, sizeof(answers));	
		}
		else
		{
			for(i = 0; szNum[i] != '\0'; i++)
			{
				if(szNum[i] > ' ')
				{
					k = 0;
					for(j = 0; j < sizeof(answers); j++)
					{
						//printf("[]%c / %c / %s[]", szNum[i], answers[j], answers); system("pause");
						if(szNum[i] == answers[j])
						{
							k++;
						}
					}
					if(k == 0)
					{
						answers[strlen(answers)] = szNum[i];
						//printf("(k = 0 %d [%c] n = %d [%s])\n", strlen(answers), answers[strlen(answers) - 1], n, answers); //system("pause");
					}
				}
			}
		}
		iCount++;
		//printf("%d", iCount);
   }
   printf("\n\n-> {n = %d} <-\n", n);

   fclose(h);
   return 0;
}
