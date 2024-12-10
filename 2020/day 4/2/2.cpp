#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTA 1100
#define SIZE_STR 100

char inp1[] = {"byr"}, inp2[] = {"iyr"}, inp3[] = {"eyr"}, inp4[] = {"hgt"}, inp5[] = {"hcl"}, inp6[] = {"ecl"}, inp7[] = {"pid"};
char c[10];

int strfind(char cVet[], char input[])
{
	int i = 0, n, j, k;
	
	memset(c, 0, sizeof(c));
	
	while(cVet[i] != '\r' && cVet[i] != '\0')
	{
		n = 0;
		for(j = 0, k = i; input[j] != '\0'; j++, k++)
		{	
			if(cVet[k] == '\r' || cVet[k] == '\0') return 0;
			if(cVet[k] != input[j]) break;
		}
		k++;
		if(input[j] == '\0')
		{
			if(strcmp(input, inp1) == 0)
			{
				memcpy(c, &cVet[k], 4);
				printf("/1:[%s]", c);
				if(cVet[k + 4] <= ' ')
				{
					if(atoi(c) >= 1920 && atoi(c) <= 2002)
					{
						printf("(1) ");
						return 1;
					}
				}
				printf("(0) ");
			}
			
			if(strcmp(input, inp2) == 0)
			{
				memcpy(c, &cVet[k], 4);
				printf("/2:[%s]", c);
				if(cVet[k + 4] <= ' ')
				{
					if(atoi(c) >= 2010 && atoi(c) <= 2020)
					{
						printf("(1) ");
						return 1;
					}
				}				
				printf("(0) ");
			}
			
			if(strcmp(input, inp3) == 0)
			{
				memcpy(c, &cVet[k], 4);
				printf("/3:[%s]", c);
				if(cVet[k + 4] <= ' ')
				{
					if(atoi(c) >= 2020 && atoi(c) <= 2030)
					{
						printf("(1) ");
						return 1;
					}
				}
				printf("(0) ");
			}
			
			if(strcmp(input, inp4) == 0)
			{
				memcpy(c, &cVet[k], 5);
				printf("/4:[%s]", c);
				if(c[3] == 'c' && c[4] == 'm')
				{
					if(cVet[k + 5] <= ' ')
					{
						c[3] = '\0';
						if(atoi(c) >= 150 && atoi(c) <= 193)
						{
							printf("(1) ");
							return 1;
						}
					}

				}
				else if(c[2] == 'i' && c[3] == 'n')
				{
					if(cVet[k + 4] <= ' ')
					{
						c[2] = '\0';
						if(atoi(c) >= 59 && atoi(c) <= 76)
						{
							printf("(1) ");
							return 1;
						}
					}					
				}
				printf("(0) ");
			}
			
			if(strcmp(input, inp5) == 0)
			{
				memcpy(c, &cVet[k], 7);
				printf("/5:[%s]", c);
				if(c[0] == '#')
				{
					if(cVet[k + 7] <= ' ')
					{
						for(int x = 1; x < 7; x++)
						{
							if((c[x] >= '0' && c[x] <= '9') || (c[x] >= 'a' && c[x] <= 'f')) //(c[x] == '0' || c[x] == '1' || c[x] == '2' || c[x] == '3' || c[x] == '4' || c[x] == '5' || c[x] == '6' || c[x] == '7' || c[x] == '8' || c[x] == '9' || c[x] == 'a' || c[x] == 'b' || c[x] == 'c' || c[x] == 'd' || c[x] == 'e' || c[x] == 'f')
							{
								n++;
							}
						}
					}
					
				}
				if(n == 6)
				{
					printf("(1) ");
					return 1;
				}
				printf("(0) ");
			}
			
			if(strcmp(input, inp6) == 0)
			{
				memcpy(c, &cVet[k], 3);
				printf("/6:[%s]", c);
				if(cVet[k + 3] <= ' ')
				{
					if(strcmp(c, "amb") == 0 || strcmp(c, "blu") == 0 || strcmp(c, "brn") == 0 || strcmp(c, "gry") == 0 || strcmp(c, "grn") == 0 || strcmp(c, "hzl") == 0 || strcmp(c, "oth") == 0)
					{
						printf("(1) ");
						return 1;
					}
				}
				printf("(0) ");
			}
			
			if(input == inp7)
			{
				memcpy(c, &cVet[k], 9);
				printf("/7:[%s]", c);
				for(int x = 0; x < 9; x++)
				{
					if(cVet[k + 9] <= ' ')
					{
						if(c[x] >= '0' && c[x] <= '9')
						{
							n++;
						}
					}	
				}
				if(n == 9)
				{
					printf("(1) ");
					return 1;
				}
				printf("(0) ");
			}
		}
		i++;
	}
	return 0;
}

int iLeArquivo(void)
{
	FILE *h;
	char szNum[SIZE_STR + 5];
	int iCount = 0, n = 0, val = 0;
	
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
			//printf("%d %d %d %d %d %d %d ", strfind(szNum, inp1), strfind(szNum, inp2), strfind(szNum, inp3), strfind(szNum, inp4), strfind(szNum, inp5), strfind(szNum, inp6), strfind(szNum, inp7));
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
   	
	fclose(h);
	return val;
}

int main()
{
	printf("\n\n%d", iLeArquivo());
}
