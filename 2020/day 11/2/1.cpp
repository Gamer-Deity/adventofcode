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
	int n, v, i, j, k, x, y;
	bool vertTop, vertBot, horLeft, horRight, diagTopLeft, diagTopRight, diagBotLeft, diagBotRight;
	
	for(i = 0; ; i++)
	{
		n = 0;
		for(j = 0; j < HEIGHT; j++)
		{
			for(k = 0; k < WIDTH; k++)
			{
				vertTop = false, vertBot = false, horLeft = false, horRight = false, diagTopLeft = false, diagTopRight = false, diagBotLeft = false, diagBotRight = false;
				
				printf("%c", cMap[j][k]);
				//printf("%c%d ", cMap[j][k], cMap[j][k]);
				if(cMap[j][k] == '#') n++;
				
				
				//printf(" [%c][%c]/", cMap[j][k], nextCMap[j][k]);				
				v = 0;
				for(y = j, x = k - 1; x > 0; x--)
				{
					switch(cMap[y][x])
					{
						case 'L':
							horLeft = true;
							break;
						case '#':
							v++;
							horLeft = true;
							break;
					}
					if(horLeft) break;
				}
				//printf("[%d]", v);
				
				for(y = j, x = k + 1; x < WIDTH - 1; x++)
				{
					//printf("{%d%c", horRight?1:0, cMap[y][x]);
					switch(cMap[y][x])
					{
						case 'L':
							horRight = true;
							break;
						case '#':
							v++;
							horRight = true;
							break;
						default:
							break;
					}
					//printf("%d}", horRight?1:0);
					if(horRight) break;
				}
				//printf("[%d]", v);
				
				for(y = j - 1, x = k; y > 0; y--)
				{
					switch(cMap[y][x])
					{
						case 'L':
							vertTop = true;
							break;
						case '#':
							v++;
							vertTop = true;
							break;
					}
					if(vertTop) break;
				}
				//printf("[%d]", v);
				
				for(y = j + 1, x = k; y < HEIGHT - 1; y++)
				{
					switch(cMap[y][x])
					{
						case 'L':
							vertBot = true;
							break;
						case '#':
							v++;
							vertBot = true;
							break;
					}
					if(vertBot) break;
				}
				//printf("[%d]", v);
				
				
				for(y = j - 1, x = k - 1; ; y--, x--)
				{
					if(x <= 0 || y <= 0) break;
					switch(cMap[y][x])
					{
						case 'L':
							diagTopLeft = true;
							break;
						case '#':
							v++;
							diagTopLeft = true;
							break;
					}
					if(diagTopLeft) break;
				}
				//printf("[%d]", v);
				
				for(y = j + 1, x = k + 1; ; y++, x++)
				{
					if(x >= WIDTH - 1 || y >= HEIGHT - 1) break;
					switch(cMap[y][x])
					{
						case 'L':
							diagBotRight = true;
							break;
						case '#':
							v++;
							diagBotRight = true;
							break;
					}
					if(diagBotRight) break;
				}
				//printf("[%d]", v);
				
				
				for(y = j - 1, x = k + 1; ; y--, x++)
				{
					if(x >= WIDTH - 1 || y <= 0) break;
					switch(cMap[y][x])
					{
						case 'L':
							diagTopRight = true;
							break;
						case '#':
							v++;
							diagTopRight = true;
							break;
					}
					if(diagTopRight) break;
				}
				//printf("[%d]", v);
				
				for(y = j + 1, x = k - 1; ; y++, x--)
				{
					if(x <= 0 || y >= HEIGHT - 1) break;
					switch(cMap[y][x])
					{
						case 'L':
							diagBotLeft = true;
							break;
						case '#':
							v++;
							diagBotLeft = true;
							break;
					}
					if(diagBotLeft) break;
				}
				//printf("[%d]", v);
				
				
				//printf("[%c][%c]/", cMap[j][k], nextCMap[j][k]);
				switch(cMap[j][k])
				{
					case 'L':
						if(v == 0) nextCMap[j][k] = '#';
						else nextCMap[j][k] = cMap[j][k];
						break;					
					case '#':
						if(v >= 5) nextCMap[j][k] = 'L';
						else nextCMap[j][k] = cMap[j][k];
						break;
					default:
						nextCMap[j][k] = cMap[j][k];
				}
				//printf("[%c][%c] ", cMap[j][k], nextCMap[j][k]);
			}
			printf("\n");
		}
		printf("> n = %d / i = %d\n\n", n, i);
		
		if(memcmp(nextCMap, cMap, sizeof(cMap)) == 0) break;
		
		memcpy(cMap, nextCMap, sizeof(cMap));	
	}
}
