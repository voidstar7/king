#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG_ENABLED 1
#define R 10
#define C 10

// generates a 10x10 char array initialized to '.'
// program walks randomly from element to element, using A - Z as labels for elements visited
// if the next step is 1) off the grid or 2) on top of an existing letter, try a different direction
// if all directions are blocked, terminate the program

int main(void)
{
	int i, j, range = 0;
	int grid[R + 2][C + 2];

	// initializes grid values to 0
	for (i = 0; i < R + 2; i++)
		for (j = 0; j < C + 2; j++)
			grid[i][j] = range;

	// overlays grid with number range, keeping 0s on outer edges
	range++;
	for (i = 1; i < R + 1; i++)
		for (j = 1; j < C + 1; range++, j++)
			grid[i][j] = range;

#ifdef DEBUG_ENABLED
	// prints grid
	for (i = 0; i < R + 2; i++)
	{
		for (j = 0; j < C + 2; j++)
			printf(" %3d", grid[i][j]);
		printf("\n");
	}
#endif
}
