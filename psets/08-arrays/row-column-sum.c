#include <stdio.h>
#include <ctype.h>
#define R 5
#define C 5
#define DIGIT (int)(buffer[i] - 48)

int main(void)
{
	int matrix[R];
	char buffer[100];
	int i, columnIndex = 0, columnNumberValue = 0, count = 0;
	printf("Enter 5 numbers: ");
	char c; 
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
		matrix[columnIndex] = columnNumberValue;
		columnNumberValue = 0;
		columnIndex++;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", matrix[i]);
	}
	printf("\n");
	return 0;
}
