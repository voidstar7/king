#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 10
#define C 10

// generates a 10x10 char array initialized to '.'
// program walks randomly from element to element, using A - Z as labels for elements visited
// if the next step is 1) off the grid or 2) on top of an existing letter, try a different direction
// if all directions are blocked, terminate the program

int main(void)
{
	int i, j;
	char start = 'A';

	char grid[R][C];
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			grid[i][j] = '.';

	srand((unsigned)time(NULL));
	int direction = rand();
	printf("%d", n % 4);

	/*
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (start <= 'Z')
			{
				printf(" %c", start);
				start++;
			}
			else
				printf(" %c", grid[i][j]);
		}
		printf("\n");
	}
	*/
}
