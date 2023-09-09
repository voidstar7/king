#include <stdio.h>

#define R n
#define C n
#define RANGE n * n

/*
 * creates a "magic square" of n size where the rows, columns, and diagonal lines have the same sum
 *
	 17  24   1   8  15
	 23   5   7  14  16
	  4   6  13  20  22
	 10  12  19  21   3
	 11  18  25   2   9
*
*/

void create_magic_square(int n, int m[R + 2][R + 2]);
void print_magic_square(int n, int m[R + 2][R + 2]);

int main(void)
{
	int n;

	printf("Enter size of magic square (odd number between 1 and 99): ");
	scanf("%d", &n);
	if (n % 2 == 0 || n < 0 || n > 99)
	{
		printf("Invalid input\n");
		return 1;
	}
	// initialize matrix with padding
	int m[R + 2][C + 2];

	create_magic_square(n, m);
	print_magic_square(n, m);

	return 0;
}

void create_magic_square(int n, int m[R + 2][R + 2])
{
	int i, j;

	// set all elements to -1
	for (i = 0; i < R + 2; i++)
		for (j = 0; j < C + 2; j++)
			m[i][j] = -1;

	// set inner square elements to 0
	for (i = 1; i < (R + 2) - 1; i++)
		for (j = 1; j < (C + 2) - 1; j++)
			m[i][j] = 0;

	// set last column between top and bottom rows to -2
	for (i = 1; i < R + 1; i++)
		m[i][C + 1] = -2;

	// start in the middle of first row of inner square
	int row = 1, col = (C + 1) / 2;
	m[row][col] = 1;

	// populate remaining numbers
	for (i = 2; i <= RANGE; i++)
	{
		// if the destination is above first row, wrap to last row
		if (m[row - 1][col + 1] == -1 && m[row + (R - 1)][col + 1] == 0)
		{
			row = row + (R - 1);
			col += 1;
			m[row][col] = i;
			continue;
		}
		else if (m[row - 1][col + 1] == 0)
		{
			row -= 1;
			col += 1;
			m[row][col] = i;
			continue;
		}
		// if the destination is to right of the last column, wrap to first column
		else if (m[row - 1][col + 1] == -2)
		{
			row -= 1;
			col = 1;
			m[row][col] = i;
			continue;
		}
		// if the destination is occupied, place the next number immediately below the last one 
		else
		{
			row += 1;
			m[row][col] = i;
			continue;
		}
	}
}

void print_magic_square(int n, int m[R + 2][R + 2])
{
	int i, j;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
			printf("%2d ", m[i][j]);
		printf("\n");
	}
}
