#include <stdio.h>
#include <ctype.h>
#define R 5
#define C 5
#define DIGIT (int)(buffer[i] - 48)

int main(void)
{
	int matrix[R][C];
	int i, j, k, columnIndex = 0, columnNumberValue = 0, count = 0;
	char buffer[100];
	char c; 

	for (k = 0; k < R; k++)
	{
		printf("Enter row %d: ", k + 1);
		while (1)
		{
			c = getchar();
			if (c == 10)
				break;
			buffer[count] = c;
			count++;
		}
		for (i = 0; i <= count; i++)
		{
			if (isdigit(buffer[i]))
			{
				if (columnNumberValue == 0)	
					columnNumberValue += DIGIT;
				else
					columnNumberValue = columnNumberValue * 10 + DIGIT;
				continue;
			}
			matrix[k][columnIndex] = columnNumberValue;
			columnNumberValue = 0;
			columnIndex++;
		}
		columnIndex = 0;
		count = 0;
	}
	

	for (i = 0; i < R; i++)
	{
		printf("row %d: ", i + 1);
		for (j = 0; j < C; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
