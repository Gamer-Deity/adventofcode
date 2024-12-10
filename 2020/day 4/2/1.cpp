#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTA 1100
#define SIZE_STR 100

int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0;
char c[SIZE_STR];

/*void strclear()
{
	for(int i = 0; i < strlen(c); i++) c[i] = '\0';
}*/

int strfind(char cVet[], char input[])
{
	int i = 0, n = 0, j, k, x;
	
	while(cVet[i] != '\r' && cVet[i] != '\0')
	{
		n = 0;
		for(j = 0, k = i; input[j] != '\0'; j++, k++)
		{	
			if(cVet[k] == '\r' || cVet[k] == '\0') return 0;
			if(cVet[k] != input[j]) break;
		}
		if(input[j] == '\0')
		{
			//char c[SIZE_STR];
			//strclear();
			i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0;
			k++;
			if(input[0] == 'b' && input[1] == 'y')
			{
				for(x = 0; x < 4; x++) c[x] = cVet[x + k];
				//printf("	%s %d %c	", c, atoi(c), cVet[x + k]); system("pause");
				if(atoi(c) >= 1920 && atoi(c) <= 2002) 
				{
					i1 = 1;
					return 1;
				}
			}
			if(input[0] == 'i' && input[1] == 'y')
			{
				for(x = 0; x < 4; x++) c[x] = cVet[x + k];
				//printf("	%s %d %c	", c, atoi(c), cVet[x + k]); system("pause");
				if(atoi(c) >= 2010 && atoi(c) <= 2020)
				{
					i2 = 1;
					return 1;
				}
			}
			if(input[0] == 'e' && input[1] == 'y')
			{
				for(x = 0; x < 4; x++) c[x] = cVet[x + k];
				//printf("	%s %d %c	", c, atoi(c), cVet[x + k]); system("pause");
				if(atoi(c) >= 2020 && atoi(c) <= 2030)
				{
					i3 = 1;
					return 1;
				}
			}
			if(input[0] == 'h' && input[1] == 'g')
			{
				//printf("1	%c %c %s %d	", cVet[0 + k], c[0], c, k); system("pause");
				for(x = 0; x < 3; x++) 
				{
					c[3] = '\0';
					c[x] = cVet[x + k];
					//printf("2	%c %c %s %d	", cVet[x + k], c[x], c, k); system("pause");
					if(atoi(c) >= 150 && atoi(c) <= 193)
					{
						int b = 0;
						for(x = 0; x < 2; x++) c[x] = cVet[x + k + 3];
						if(c[0] == 'c' && c[1] == 'm') 
						{
							i4 = 1;
							return 1;
							//b = 1;
							//printf("3	//%c %s %d %c//	", c[x], c, b, cVet[x + k]); system("pause");
						}
					}
				}
				//printf("	/%s %d %c/	", c, atoi(c), cVet[x + k]); system("pause");
				for(x = 0; x < 2; x++) 
				{
					c[2] = '\0';
					c[x] = cVet[x + k];
					//printf("4	%c %c %s // %d /%d/	", cVet[x + k], c[x], c, k, atoi(c)); system("pause");
					if(atoi(c) >= 59 && atoi(c) <= 76)
					{
						int b = 0;
						for(x = 0; x < 2; x++) c[x] = cVet[x + k + 2];
						//printf("	///%s %d %c///	", c, b, cVet[x + k]); system("pause");
						if(c[0] == 'i' && c[1] == 'n') 
						{
							i4 = 1;
							return 1;
							//b = 1;
							//printf("	{/%s %d %c/}	", c, b, cVet[x + k]); system("pause");
						}
					}
				}
			}
			if(input[0] == 'h' && input[1] == 'c')
			{
				for(x = 0; x < 7; x++) c[x] = cVet[x + k];
				if(c[0] == '#')
				{
					for(x = 1; x < 7; x++)
					{
						if(c[x] == '0' || c[x] == '1' || c[x] == '2' || c[x] == '3' || c[x] == '4' || c[x] == '5' || c[x] == '6' || c[x] == '7' || c[x] == '8' || c[x] == '9' || c[x] == 'a' || c[x] == 'b' || c[x] == 'c' || c[x] == 'd' || c[x] == 'e' || c[x] == 'f')
						{
							n++;
						}
					}
				}
				if(n == 6)
				{
					i5 = 1;
					return 1;
				}
			}
			if(input[0] == 'e' && input[1] == 'c')
			{
				for(x = 0; x < 3; x++) c[x] = cVet[x + k];
				//printf("	%s %d %c	", c, atoi(c), cVet[x + k]); system("pause");
				if((c[0] == 'a' && c[1] == 'm' && c[2] == 'b') || (c[0] == 'b' && c[1] == 'l' && c[2] == 'u') || (c[0] == 'b' && c[1] == 'r' && c[2] == 'n') || (c[0] == 'g' && c[1] == 'r' && c[2] == 'y') || (c[0] == 'g' && c[1] == 'r' && c[2] == 'n') || (c[0] == 'h' && c[1] == 'z' && c[2] == 'l') || (c[0] == 'o' && c[1] == 't' && c[2] == 'h'))//"amb" || c == "blu" || c == "brn" || c == "gry" || c == "grn" || c == "hzl" || c == "oth")
				{
					i6 = 1;
					return 1;
				}
			}
			if(input[0] == 'p' && input[1] == 'i')
			{
				c[10] = '\0';
				int num = 0;
				for(x = 0; x < 9; x++)
				{
					c[x] = cVet[x + k];
					if(c[x] == '0' || c[x] == '1' || c[x] == '2' || c[x] == '3' || c[x] == '4' || c[x] == '5' || c[x] == '6' || c[x] == '7' || c[x] == '8' || c[x] == '9' && (c[10] <= ' '))
					{
						num++;
					}
				}
				//printf("	/%s/%d/%d/%c/	", c, atoi(c), num, cVet[x + k]); system("pause");
				if(num == 9)
				{
					i7 = 1;
					return 1;
				}
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
    		printf(" / %d %d %d %d %d %d %d / {%d} / n2 = %d\r\n\r\n", i1, i2, i3, i4, i5, i6, i7, val, n); //system("pause");
		}
		else
		{
			//printf("%d %d %d %d %d %d %d / %d %d %d %d %d %d %d ", strfind(szNum, inp1), strfind(szNum, inp2), strfind(szNum, inp3), strfind(szNum, inp4), strfind(szNum, inp5), strfind(szNum, inp6), strfind(szNum, inp7), i1, i2, i3, i4, i5, i6, i7);
			n += strfind(szNum, inp1) + strfind(szNum, inp2) + strfind(szNum, inp3) + strfind(szNum, inp4) + strfind(szNum, inp5) + strfind(szNum, inp6) + strfind(szNum, inp7);
		}
		iCount++;
	} 	while (!feof(h) && iCount < MAX_LISTA);
	
	printf("\nn1 = %d", n);
   	if(n >= 7)
	{
		val++;
		//n = 0;
	}
	n = 0;
   	printf(" / %d %d %d %d %d %d %d / {%d} / n2 = %d\r\n\r\n", i1, i2, i3, i4, i5, i6, i7, val, n); //system("pause");
	
	printf("\n\nLines: %d\n", iCount);
	fclose(h);
	return val;
}

int main()
{
	printf("%d", iLeArquivo());
}
