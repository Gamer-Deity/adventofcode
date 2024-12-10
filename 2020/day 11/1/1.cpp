#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HEIGHT 12
#define WIDTH 13

int main()
{
	char cMap[HEIGHT][WIDTH] = {
		"............",
		".L.LL.LL.LL.",
		".LLLLLLL.LL.",
		".L.L.L..L...",
		".LLLL.LL.LL.",
		".L.LL.LL.LL.",
		".L.LLLLL.LL.",
		"...L.L......",
		".LLLLLLLLLL.",
		".L.LLLLLL.L.",
		".L.LLLLL.LL.",
		"............"
	};
	char nextCMap[HEIGHT][WIDTH];
	int n, x, i, j, k;
	
	for(i = 0; ; i++)
	{
		n = 0;
		for(j = 0; j < HEIGHT; j++)
		{
			for(k = 0; k < WIDTH; k++)
			{
				printf("%c", cMap[j][k]);
				if(cMap[j][k] == '#') n++;
				
				x = 0;
				for(int a = 0; a < 3; a++)
				{
					for(int b = 0; b < 3; b++)
					{
						if(a != 1 || b != 1)
						{
							if(cMap[(j - 1) + a][(k - 1) + b] == '#') x++;
						}
					}
				}
				
				switch(cMap[j][k])
				{
					case 'L':
						if(x == 0) nextCMap[j][k] = '#';
						break;					
					case '#':
						if(x >= 4) nextCMap[j][k] = 'L';
						break;
					default:
						nextCMap[j][k] = cMap[j][k];
				}
			}
			printf("\n");
		}
		printf("> n = %d / i = %d\n\n", n, i);
		
		if(memcmp(nextCMap, cMap, sizeof(cMap)) == 0) break;
		
		memcpy(cMap, nextCMap, sizeof(cMap));	
	}
}
