#include <stdio.h>
#include <ctype.h>
#define R 5 
#define C 5

// prompts for a 5x5 array of integers and displays the sum of each row and column
int main(void)
{
	int rowSum[R] = {0};
	int columnSum[C] = {0};
	int n = 0;

	printf("Enter %d numbers in each row\n", C);
	for (int i = 0; i <= R; i++)
	{
		printf("Enter row %d: ", i + 1);
		while (1)
		{
			n = getchar();
			if (isdigit(n))
				rowSum[i] += (int)n - 48;
			else if (n == 32)
				continue;
			else if (n == 10)
				break;
			else
			{
				printf("Invalid entry\n");
				return 1;
			}
		}
	}
	printf("Row totals: ");
	for (int k = 0; k < R; k++)
		printf("%d ", rowSum[k]);
	printf("\n");
	return 0;
}
