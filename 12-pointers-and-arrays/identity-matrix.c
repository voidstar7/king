#include <stdio.h>

#define ROW 8 
#define COL 8
#define SIZE ROW * COL

void initArray(int *ptr, int rows, int cols);
void processArray(int *ptr, int rows, int cols);
void printArray(int *ptr, int rows, int cols);

int main(void)
{
	int identityMatrix[ROW][COL];
	int *ptr = &identityMatrix[0][0];

	initArray(ptr, ROW, COL);
	processArray(ptr, ROW, COL);
	printArray(ptr, ROW, COL);
}

void initArray(int *ptr, int rows, int cols)
{
	for (int i = 0; i < SIZE; i++)
		*(ptr + i) = 0;
}

void processArray(int *ptr, int rows, int cols)
{
	int zeros = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (i == 0)
		{
			*(ptr + i) = 1;
			continue;
		}
		if (*(ptr + i) == 0)
			zeros++;
		if (zeros == ROW)
		{
			*(ptr + (i + 1)) = 1;
			zeros = 0;
		}
	}
}

void printArray(int *ptr, int rows, int cols)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (i % ROW == 0 && i != 0)
			printf("\n");
		printf("%d ", *(ptr + i));
	}
	printf("\n");
}
