#include <stdio.h>
#include <ctype.h>
#define R 5
#define C 5
#define DIGIT (int)(rowBuffer[i] - 48)

int main(void)
{
	int matrix[R];
	char rowBuffer[100];
	int i, rowIndex = 0, rowNumberValue = 0, count = 0;
	printf("Enter 5 numbers: ");
	char c; 
	while (1)
	{
		c = getchar();
		if (c == 10)
			break;
		rowBuffer[count] = c;
		count++;
	}
	for (i = 0; i <= count; i++)
	{
		if (isdigit(rowBuffer[i]))
		{
			if (rowNumberValue == 0)  
				rowNumberValue += DIGIT;
			else
				rowNumberValue = rowNumberValue * 10 + DIGIT;
			continue;
		}
		matrix[rowIndex] = rowNumberValue;
		rowNumberValue = 0;
		rowIndex++;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", matrix[i]);
	}
	printf("\n");
	return 0;
}
