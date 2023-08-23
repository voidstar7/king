#include <stdio.h>

#define R 10
#define C 10

// generates a 10x10 char array initialized to '.'
// program walks randomly from element to element, using A - Z as labels for elements visited
// terminates if the walk goes outside the bounds of the grid or is blocked from moving further

int main(void)
{
	int i, j;

	char grid[R][C];
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			grid[i][j] = '.';

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			printf(" %c", grid[i][j]);
		printf("\n");
	}
}
