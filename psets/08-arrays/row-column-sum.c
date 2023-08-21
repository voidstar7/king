#include <stdio.h>
#include <ctype.h>
#define DIGIT (int)(row[i] - 48)

int main(void)
{
	int array[5];
	char row[100];
	int i, arrayIndex = 0, rowNumberValue = 0, count = 0;
	printf("Enter 5 numbers: ");
	char c; 
	while (1)
	{
		c = getchar();
		if (c == 10)
			break;
		row[count] = c;
		count++;
	}
	for (i = 0; i <= count; i++)
	{
		if (isdigit(row[i]))
		{
			if (rowNumberValue == 0)  
				rowNumberValue += DIGIT;
			else
				rowNumberValue = rowNumberValue * 10 + DIGIT;
			continue;
		}
		array[arrayIndex] = rowNumberValue;
		rowNumberValue = 0;
		arrayIndex++;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
