#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LISTA 20
#define PREAMB_SIZE 5

int main()
{
	bool bInput[MAX_LISTA];
	int input[MAX_LISTA] = {
		35,
		20,
		15,
		25,
		47,
		40,
		62,
		55,
		65,
		95,
		102,
		117,
		150,
		182,
		127,
		219,
		299,
		277,
		309,
		576
	};
	int i, j, k;
	
	memset(bInput, 0, sizeof(bInput));
	for(i = PREAMB_SIZE; i < MAX_LISTA; i++)
	{
		for(j = 1; j <= PREAMB_SIZE; j++)
		{
			for(k = 1; k <= PREAMB_SIZE; k++)
			{
				if(input[i] == input[i - j] + input[i - k])
				{
					bInput[i] = true;
					printf("%d = %d + %d -> i = %d\n", input[i], input[i - j], input[i - k], i);
					//system("pause");
				}
			}
		}
	}
	printf("\n\n");
	
	for(i = PREAMB_SIZE; i < MAX_LISTA; i++)
	{
		if(!bInput[i])
		{
			printf("%d -> i=%d\n", input[i], i);
		}
	}
}
