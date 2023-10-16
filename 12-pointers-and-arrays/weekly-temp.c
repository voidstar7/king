#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//#define debug
#define D 7
#define H 24

void initArr(const int arr[][H]);
int printDay(const int arr[][H], int selectedDay, int i);
int findLargest(int *a, int i);
bool search(int *a, int *key, int selectedDay);

int main(void)
{
	const int arr[D][H];
	int daySelect, key, i;
	initArr(arr);

	printf("Highest temperatures per day:\n");
	for (i = 0; i < D; i++)
	{
		switch (i)
		{
			case 0: printf("Sun (1)| "); break;
			case 1: printf("Mon (2)| "); break;
			case 2: printf("Tue (3)| "); break;
			case 3: printf("Wed (4)| "); break;
			case 4: printf("Thu (5)| "); break;
			case 5: printf("Fri (6)| "); break;
			case 6: printf("Sat (7)| "); break;
		}
		printf("%d\n", findLargest(arr, i));
	}

	printf("What day do you want to print? (1 - 7) ");
		scanf("%d", &daySelect);
	if (daySelect < 1 || daySelect > 7)
	{
		printf("Invalid entry\n");
		return 1;
	}
	daySelect--;
	for (i = 0; i < H; i++)
		printf("%d ", printDay(arr, daySelect, i));
	printf("\n");

	printf("Which temperature do you want to search for? ");
		scanf("%d", &key);
	if (search(&arr[0][0], &key, daySelect))
		printf("%d was found in day %d\n", key, daySelect + 1);
	else
		printf("%d was not found in day %d\n", key, daySelect + 1);
	return 0;
}

void initArr(const int arr[][H])
{
	srand(time(NULL));
	int *ptrArr;
	int i;
	for (ptrArr = &arr[0][0], i = 0; 
			ptrArr <= &arr[D - 1][H - 1]; 
			ptrArr++, i++)
	{
		*ptrArr = rand() % 30 + 1;
#ifdef debug
		printf("%p - [%d] - %d\n", ptrArr, i,  *ptrArr);
#endif
	}
	printf("\n         ");
	for (int l = 1; l <= H; l++)
		printf("%2d ", l);
	printf("\n         ");
	for (int m = 1; m <= H; m++)
		printf("___");
	printf("\n");
	for (int j = 0; j < D; j++)
	{
		switch (j)
		{
			case 0: printf("Sun (1)| "); break;
			case 1: printf("Mon (2)| "); break;
			case 2: printf("Tue (3)| "); break;
			case 3: printf("Wed (4)| "); break;
			case 4: printf("Thu (5)| "); break;
			case 5: printf("Fri (6)| "); break;
			case 6: printf("Sat (7)| "); break;
		}
		for (int k = 0; k < H; k++)
			printf("%2d ", arr[j][k]);
		printf("\n");
	}
}

int findLargest(int *a, int i)
{
	int *p;
	int largest = *p;
	for (p = a + (i * H);
			p < (a + (i * H)) + (H - 1);
			p++)
	{
		if (*(p + 1) > largest)
			largest = *(p + 1);
	}
	return largest;
}

int printDay(const int arr[][H], int selectedDay, int i)
{
	int *ptrArr = &arr[0][0];
	return *(ptrArr + (H * selectedDay) + i);
}

bool search(int *a, int *key, int selectedDay)
{
	int *p;
	for (p = a + (H * selectedDay);
			p < a + ((H * selectedDay) + H);
			p++)
	{
		if (*p == *key)
			return true;
		else
			continue;
	}
	return false;
}
