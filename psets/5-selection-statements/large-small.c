#include <stdio.h>

// prompts for four integers and finds the smallest and largest using as few if statements as possible (4)

int main(void) {
	int sum, smallest, largest, i, j, k, l;
	printf("Enter four integers: "); 
	scanf("%d %d %d %d", &i, &j, &k, &l);	
	sum = i + j + l + k;

	if (i < j && i < k && i < l) {
		smallest = i;
	}
	else if (j < i && j < k && j < l) {
		smallest = j;
	}
	else if (k < i && k < j && k < l) {
		smallest = k;
	}
	else if (l < i && l < k && l < j) {
		smallest = l;
	}
	printf("Smallest: %d\n", smallest);
	// printf("Largest: %d\n", largest);
	return 0;
}
