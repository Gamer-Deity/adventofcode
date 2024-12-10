#include <stdio.h>
#include <stdlib.h>

#define MAX_LISTA 1100
#define SIZE_STR 100

int passNum = 0;

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
	int iCount = 0, val = 0;
	char inp1[] = {"byr"}, inp2[] = {"iyr"}, inp3[] = {"eyr"}, inp4[] = {"hgt"}, inp5[] = {"hcl"}, inp6[] = {"ecl"}, inp7[] = {"pid"};
	bool b1, b2, b3, b4, b5, b6, b7;
	
	h = fopen("input.txt", "rt");
	if (h == NULL) return -1;
	
	do
	{
		if (fgets(szNum, sizeof(szNum), h) == NULL) break;
    	// szNum - > linha lida
    	printf("%s", szNum);
    	if(szNum[0] < ' ')
    	{
    		passNum++;
    		if(b1 && b2 && b3 && b4 && b5 && b6 && b7)
			{
				val++;
				//printf(" / {%d} / ", val);
			}
			b1 = false, b2 = false, b3 = false, b4 = false, b5 = false, b6 = false, b7 = false;
			printf(" / {%d} / \n", val);
		}
		else
		{
			if(strfind(szNum, inp1)) b1 = true;
			if(strfind(szNum, inp2)) b2 = true;
			if(strfind(szNum, inp3)) b3 = true;
			if(strfind(szNum, inp4)) b4 = true;
			if(strfind(szNum, inp5)) b5 = true;
			if(strfind(szNum, inp6)) b6 = true;
			if(strfind(szNum, inp7)) b7 = true;

			printf("%d %d %d %d %d %d %d ", strfind(szNum, inp1), strfind(szNum, inp2), strfind(szNum, inp3), strfind(szNum, inp4), strfind(szNum, inp5), strfind(szNum, inp6), strfind(szNum, inp7));
		}
		iCount++;
	} 	while (!feof(h) && iCount < MAX_LISTA);
	
	if(b1 && b2 && b3 && b4 && b5 && b6 && b7)
	{
		val++;
		//printf(" / {%d} / ", val);
	}
	b1 = false, b2 = false, b3 = false, b4 = false, b5 = false, b6 = false, b7 = false;
	printf("\n / {%d} / \n", val);
	
	printf("\n\nLines: %d\n", iCount);
	printf("passNum: %d\n", passNum);
	fclose(h);
	return val;
}

int main()
{
	printf("\nVal: %d\n", iLeArquivo());
}
