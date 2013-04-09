#include <stdio.h>
#define XAXIS 5
#define YAXIS 8
#define ZAXIS 12
#define TIMEAXIS 2

int main()
{
	int array[XAXIS][YAXIS][ZAXIS][TIMEAXIS];

	int x;
	for (x = 0; x < XAXIS; x++)
	{
		int y;
		for (y = 0; y < YAXIS; y++)
		{
			int z;
			for (z = 0; z < ZAXIS; z++)
			{
				int time;
				for (time = 0; time < TIMEAXIS; time++)
				{
					array[x][y][z][time] = x*y*z*time;
				}
			}
		}
	}
	
	printf("How or why would we even display this?\n");
	return 0;
}