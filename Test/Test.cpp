#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*int strfind(char cVet[], char input)
{
	int i = 0;
	while(cVet[i] != '\0')
	{
		if(input == cVet[i]) return 1;
		//printf(" %c{found}%c ", input, cVet[i]);
		i++;
	}
	return 0;
}

int main()
{
	char szNum[] = "abodeprhklf", answers[27];
	
	strcpy(answers, "abcdefghijklmnopqrstuvwxyz");
	
	for(int j = 0; j < sizeof(answers) - 1; j++)
	{
		printf("%d - %d - %c\n", strfind(szNum, answers[j]), j, answers[j]);
		
		if(strfind(szNum, answers[j]) != 1)
		{
			answers[j] = ' ';
			printf("\n[%s]\n", answers); system("pause");
		}
		else
		{
			printf("aa");
		}
		printf("%d", j);
	}
}*/

int main()
{
	int a = 18;
	int* b = &a;
	int** c = &b;
	int*** d = &c;
	int**** e = &d;
	
	printf("%d, %d, %d, %d, %d <-> %d, %d, %d, %d, %d", e, d, c, b, a, ****e, ***e, **e, *e, e);
}
