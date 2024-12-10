#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define SIZE_STR 26
#define MAX_LISTA 2120

int strfind(char cVet[], char input)
{
	int i = 0;
	while(cVet[i] != '\0')
	{
		if(input == cVet[i]) return 1;
		i++;
	}
	return 0;
}

int main(void)
{
	FILE *h;
	char szNum[SIZE_STR + 5], answers[27];
	int iCount = 0, n = 0, j, i;
	
	h = fopen("input.txt", "rt"); //fopen("input2.txt", "rt");
	if (h == NULL)
	{
		printf("File not found.");
		return -1;
	}
	
	strcpy(answers, "abcdefghijklmnopqrstuvwxyz");
	//printf("[%s]\n", answers); system("pause");
	while (!feof(h) && iCount < MAX_LISTA) {
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	// szNum - > linha lida
    	printf("%s", szNum);		

		if(szNum[0] <= ' ')
		{
			for(i = 0; i < sizeof(answers) - 1; i++)
			{
				if(answers[i] != ' ') n++;
			}
			
			printf("(n = %d)\n\n", n);
			strcpy(answers, "abcdefghijklmnopqrstuvwxyz");
		}
		else
		{
			for(j = 0; j < sizeof(answers) - 1; j++)
			{
				if(strfind(szNum, answers[j]) != 1)
				{
					answers[j] = ' ';
					//printf("\n[%s]\n", answers); system("pause");
				}
				//printf("%d", j);
			}
		}
		iCount++;
   }
   printf("\n\n-> {n = %d} <-\n", n);

   fclose(h);
   return 0;
}
