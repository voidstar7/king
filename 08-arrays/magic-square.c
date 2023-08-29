#include <stdio.h>

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
}
