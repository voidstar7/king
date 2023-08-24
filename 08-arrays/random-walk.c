#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

//#define DEBUG
#define R 10
#define C 10
#define UP grid[rowPosition - 1][columnPosition]
#define RIGHT grid[rowPosition][columnPosition + 1]
#define DOWN grid[rowPosition + 1][columnPosition]
#define LEFT grid[rowPosition][columnPosition - 1]

// generates a 10x10 char array initialized to '.'
// program walks randomly from element to element, using A - Z as labels for elements visited
// if the next step is 1) off the grid or 2) on top of an existing letter, try a different direction
// if all directions are blocked\n, terminate the program

int main(void)
{
	int i, j, move, rowPosition, columnPosition, letter = 'A', range = 100;
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
	rowPosition = 1, columnPosition = 1;
	grid[rowPosition][columnPosition] = letter;
	letter++;

	// seed rng
	srand((unsigned)time(NULL));

	// initialize flags for blocked movement
	bool upBlocked = false, rightBlocked = false, downBlocked = false, leftBlocked = false;

	// begin movement
	for (i = 1; i < 26; i++)
	{
		if (upBlocked == true && rightBlocked == true && downBlocked == true && leftBlocked == true)
		{
		#ifdef DEBUG
			printf("Movement is blocked after %d/25 moves\n", i);
		#endif
			break;
		}
		move = rand() % 4;
		#ifdef DEBUG
		if (move == 0)
			printf("Attempting to move Up\n");
		else if (move == 1)
			printf("Attempting to move Right\n");
		else if (move == 2)
			printf("Attempting to move Down\n");
		else
			printf("Attempting to move Left\n");
		#endif
		switch (move)
		{
			case 0:
				if (UP == 0 || (UP >= 65 && UP <= 90))
				{
				#ifdef DEBUG
					printf("Up is blocked\n");
				#endif
					upBlocked = true;
					i--;
					break;
				}
				#ifdef DEBUG
					printf("Successfully moved Up (%i/25)\n", i);
				#endif
				UP = letter;
				letter++;
				rowPosition--;
				upBlocked = false; rightBlocked = false; downBlocked = false; leftBlocked = false;
				break;
			case 1:
				if (RIGHT == 0 || (RIGHT >= 65 && RIGHT <= 90))
				{
				#ifdef DEBUG
					printf("Right is blocked\n");
				#endif
					rightBlocked = true;
					i--;
					break;
				}
				#ifdef DEBUG
					printf("Successfully moved Right (%i/25)\n", i);
				#endif
				RIGHT = letter;
				letter++;
				columnPosition++;
				upBlocked = false; rightBlocked = false; downBlocked = false; leftBlocked = false;
				break;
			case 2:
				if (DOWN == 0 || (DOWN >= 65 && DOWN <= 90))
				{
				#ifdef DEBUG
					printf("Down is blocked\n");
				#endif
					downBlocked = true;
					i--;
					break;
				}
				#ifdef DEBUG
					printf("Successfully moved Down (%i/25)\n", i);
				#endif
				DOWN = letter;
				letter++;
				rowPosition++;
				upBlocked = false; rightBlocked = false; downBlocked = false; leftBlocked = false;
				break;
			case 3:
				if (LEFT == 0 || (LEFT >= 65 && LEFT <= 90))
				{
				#ifdef DEBUG
					printf("Left is blocked\n");
				#endif
					leftBlocked = true;
					i--;
					break;
				}
				#ifdef DEBUG
					printf("Successfully moved Left (%i/25)\n", i);
				#endif
				LEFT = letter;
				letter++;
				columnPosition--;
				upBlocked = false; rightBlocked = false; downBlocked = false; leftBlocked = false;
				break;
			default:
				printf("Unexpected error\n");
				return 1;
		}
	}

	for (i = 1; i < R + 1; i++)
	{
		for (j = 1; j < C + 1; j++)
		if (grid[i][j] >= 100)
			printf(" . ");
		else
			printf(" %c ", (char)grid[i][j]);
		printf("\n");
	}
	return 0;
}
