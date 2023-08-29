#include <stdio.h>

#define R n
#define C n
#define RANGE n * n

int main(void)
{
	int n, i, j, k;

	printf("Enter size of magic square (odd number between 1 and 99): ");
	scanf("%d", &n);
	if (n % 2 == 0 || n < 0 || n > 99)
	{
		printf("Invalid input\n");
		return 1;
	}
	/*
	 place first number in the middle of row 0
	 place subsequent numbers up 1 row and right 1 column
		 if the destination is above first row, wrap to last row
		 if the destination is to right of the last column, wrap to first column
		 if the destination is occupied, place the next number immediately below the last one 

	 17  24   1   8  15
	 23   5   7  14  16
	  4   6  13  20  22
	 10  12  19  21   3
	 11  18  25   2   9
 */

	// initialize matrix with padding
	int m[R + 2][C + 2];
	
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
	int row = 1, col = (R + 1) / 2;
	m[row][col] = 1;

	// populate remaining numbers
	for (i = 2; i <= RANGE; i++)
	{
		// if the destination is above first row, wrap to last row
		if (m[row - 1][col + 1] < 0)
		{
			row = row + (R - 1);
			col += 1;
			m[row][col] = i;
			continue;
		}
		row -= 1;
		col += 1;
		m[row][col] = i;
		break;



	}
		


	// print magic square
	for (i = 0; i < R + 2; i++)
	{
		for (j = 0; j < C + 2; j++)
			printf("%2d ", m[i][j]);
		printf("\n");
	}
}
