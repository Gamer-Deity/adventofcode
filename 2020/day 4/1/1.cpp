#include <stdio.h>
#include <stdlib.h>

#define MAX_LISTA 1100
#define SIZE_STR 100

int strfind(char cVet[], char input[])
{
	int i = 0, n = 0, j, k;
	while(cVet[i] != '\r' && cVet[i] != '\0')
	{
		n = 0;
		for(j = 0, k = i; input[j] != '\0'; j++, k++)
		{	
			if(cVet[k] == '\r' || cVet[k] == '\0') return 0;
			if(cVet[k] != input[j]) break;
		}
		if(input[j] == '\0') return 1;
		i++;
	}
	return 0;
}

int iLeArquivo(void)
{
	FILE *h;
	char szNum[SIZE_STR + 5];
	int iCount = 0, n = 0, val = 0;
	char inp1[] = {"byr"}, inp2[] = {"iyr"}, inp3[] = {"eyr"}, inp4[] = {"hgt"}, inp5[] = {"hcl"}, inp6[] = {"ecl"}, inp7[] = {"pid"};
	
	h = fopen("input.txt", "rt");
	if (h == NULL) return -1;
	
	do
	{
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	// szNum - > linha lida
    	printf("%s", szNum);
    	if(szNum[0] < ' ')
    	{
    		printf("n1 = %d", n);
    		if(n >= 7)
			{
				val++;
				//n = 0;
			}
			n = 0;
    		printf(" / {%d} / n2 = %d\r\n\r\n", val, n); //system("pause");
		}
		else
		{
			n += strfind(szNum, inp1) + strfind(szNum, inp2) + strfind(szNum, inp3) + strfind(szNum, inp4) + strfind(szNum, inp5) + strfind(szNum, inp6) + strfind(szNum, inp7);
			printf("%d %d %d %d %d %d %d ", strfind(szNum, inp1), strfind(szNum, inp2), strfind(szNum, inp3), strfind(szNum, inp4), strfind(szNum, inp5), strfind(szNum, inp6), strfind(szNum, inp7));
		}
		iCount++;
	} 	while (!feof(h) && iCount < MAX_LISTA);
	
	printf("\nn1 = %d", n);
   	if(n >= 7)
	{
		val++;
	}
	n = 0;
   	printf(" / {%d} / n2 = %d\r\n", val, n); //system("pause");
	
	printf("\n\nLines: %d\n", iCount);
	fclose(h);
	return val;
}

int main()
{
	printf("%d", iLeArquivo());
}
