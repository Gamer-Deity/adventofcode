#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LISTA 9
#define SIZE_STR 9


int main()
{
	char cInput[MAX_LISTA][SIZE_STR] = {
		"nop +0",
		"acc +1",
		"jmp +4",
		"acc +3",
		"jmp -3",
		"acc -99",
		"acc +1",
		"jmp -4",
		"acc +6",
	};
	bool bInput[MAX_LISTA], bList[MAX_LISTA];
	char c[5];
	int i, j, k, acc;
	bool canCheck = true;
	
	acc = 0;
	memset(bInput, 0, sizeof(bInput));
	memset(bList, 0, sizeof(bList));
	
	for(i = 0; i < MAX_LISTA; i++)
	{
		if(cInput[i][0] == 'n' || cInput[i][0] == 'j')
		{
			bList[i] = true;		
		}
		if(bList[i]) printf(">[%s]<\n", cInput[i]);
	}

	for(k = 0; k < MAX_LISTA; k++)
	{
		//printf("{%s}\n", cInput[k]);
		if(bList[k])
		{
			printf("\n//%s//", cInput[k]);
			if(cInput[k][0] == 'n') cInput[k][0] = 'j';
			else if(cInput[k][0] == 'j') cInput[k][0] = 'n';
			printf("%c,%s//\n", cInput[k][0], cInput[k]);
			
			memset(bInput, 0, sizeof(bInput));
			acc = 0;
			for(i = 0; i < MAX_LISTA;)
			{
				memset(c, 0, sizeof(c));
				j = 0;
				
				if(bInput[i])
				{
					bList[k] = false;
					//printf("--%s--", cInput[i]); system("pause");
					break;
				}
				
				bInput[i] = true;
				
				if(cInput[i][0] == 'n')
				{
					printf("%s -> i=%d\n", cInput[i], i);
					i++;
					//system("pause");
				}	
				else if(cInput[i][0] == 'a')
				{
					while(cInput[i][j + 4] != '\0')
					{
						c[j] = cInput[i][j + 4];
						j++;
					}
					printf("%s -> i=%d\n", cInput[i], i);
					acc += atoi(c);
					i++;
					//system("pause");
				}
				else if(cInput[i][0] == 'j')
				{
					while(cInput[i][j + 4] != '\0')
					{
						c[j] = cInput[i][j + 4];
						j++;
					}
					printf("%s -> i=%d\n", cInput[i], i);
					i += atoi(c);
					//system("pause");
				}
			}
			if(cInput[k][0] == 'n') cInput[k][0] = 'j';
			else if(cInput[k][0] == 'j') cInput[k][0] = 'n';
			
			//printf("\n\nacc = %d\n", acc); //system("pause");
			//printf("\n//%c,%s//", cInput[k][0], cInput[k]);
			//printf("\nk = %d\n", k);
		}
	}
	
	printf("\n\nacc = %d\n", acc);
}
