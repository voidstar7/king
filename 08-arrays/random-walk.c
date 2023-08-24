#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DEBUG_ENABLED 1
#define R 10
#define C 10
#define UP grid[rowPosition][columnPosition] - R
#define RIGHT grid[rowPosition][columnPosition] + 1
#define DOWN grid[rowPosition][columnPosition] + R
#define LEFT grid[rowPosition][columnPosition] - 1

// generates a 10x10 char array initialized to '.'
// program walks randomly from element to element, using A - Z as labels for elements visited
// if the next step is 1) off the grid or 2) on top of an existing letter, try a different direction
// if all directions are blocked, terminate the program

int main(void)
{
	int i, j, move, letter, range = 100;
	int grid[R + 2][C + 2];

	// initialize grid values to 0
	for (i = 0; i < R + 2; i++)
		for (j = 0; j < C + 2; j++)
			grid[i][j] = 0;

	// overlay grid with number range, keeping 0s on outer edges
	// range overlay begins at 100 to distinguish char from int values later
	for (i = 1; i < R + 1; i++)
		for (j = 1; j < C + 1; range++, j++)
			grid[i][j] = range;

	// start at top left corner
	int rowPosition = 1, columnPosition = 1;
	grid[rowPosition][columnPosition] = 'A';

	// seed rng
	srand((unsigned)time(NULL));

	// initialize flags for blocked movement
	bool upBlocked = false, rightBlocked = false, downBlocked = false, leftBlocked = false;

	// begin movement
	for (i = 1; i < 26; i++)
	{
		if (upBlocked == true && rightBlocked == true && downBlocked == true && leftBlocked == true)
		{
		#ifdef DEBUG_ENABLED
			printf("Movement is blocked\n");
		#endif
			return 1;
		}
		move = rand() % 4;
		switch (move)
		{
			/*
			case 0: // up
			case 1: // right
			case 2: // down
			case 3: // left
			*/
		}
	}

#ifdef DEBUG_ENABLED
	// print grid
	for (i = 0; i < R + 2; i++)
	{
		for (j = 0; j < C + 2; j++)
			printf(" %4d", grid[i][j]);
		printf("\n");
	}
#endif
}
