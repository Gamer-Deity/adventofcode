#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LISTA 20
#define PREAMB_SIZE 5

int main()
{
	bool bInput[MAX_LISTA];
	int cInput[MAX_LISTA] = {
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
	int iInput, inpLocation, sum = 0, iMin, iMax;
	
	memset(bInput, 0, sizeof(bInput));
	for(i = PREAMB_SIZE; i < MAX_LISTA; i++)
	{
		for(j = 1; j <= PREAMB_SIZE; j++)
		{
			for(k = 1; k <= PREAMB_SIZE; k++)
			{
				if(cInput[i] == cInput[i - j] + cInput[i - k])
				{
					bInput[i] = true;
					printf("%d = %d + %d -> i = %d\n", cInput[i], cInput[i - j], cInput[i - k], i);
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
			printf("%d -> i=%d\n", cInput[i], i);
			iInput = cInput[i];
			inpLocation = i;
		}
	}
	//printf("%d %d", iInput, inpLocation);
	
	for(i = 0; i < inpLocation; i++)
	{
		iMin = cInput[i];
		iMax = cInput[i];
		sum = cInput[i];
		for(j = i + 1; j < inpLocation; j++)
		{
			printf("%d -> i=%d\n", sum, i);
			printf("iMin=%d / iMax=%d\n\n", iMin, iMax);
			if(sum <= iInput)
			{
				if(sum == iInput) break;
				sum += cInput[j];
				if(iMin > cInput[j]) iMin = cInput[j];
				if(iMax < cInput[j]) iMax = cInput[j];
				
			}
			else break;
		}
		if(sum == iInput) break;
	}
	printf("\nSum = %d -> iMin=%d / iMax=%d -> iMin + iMax = %d\n\n", sum, iMin, iMax, iMin + iMax);
}
