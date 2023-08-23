#include <stdio.h>

// prompts for four integers and finds the smallest and largest using as few if statements as possible (4)

int main(void) {
	int sum, smallest, largest, i, j, k, l;
	printf("Enter four integers: "); 
	scanf("%d %d %d %d", &i, &j, &k, &l);	

	if (i < j && i < k && i < l) {
		smallest = i;
		if (j > k && j > l) {
			largest = j;
		}
		else if (k > j && k > l) {
			largest = k;
		}
		else {
			largest = l;
		}
	}
	else if (j < i && j < k && j < l) {
		smallest = j;
		if (i > k && i > l) {
			largest = i;
		}
		else if (k > i && k > l) {
			largest = k;
		}
		else {
			largest = l;
		}
	}
	else if (k < i && k < j && k < l) {
		smallest = k;
		if (i > j && i > l) {
			largest = i;
		}
		else if (j > i && j > l) {
			largest = j;
		}
		else {
			largest = l;
		}
	}
	else if (l < i && l < k && l < j) {
		smallest = l;
		if (i > j && i > k) {
			largest = i;
		}
		else if (j > i && j > k) {
			largest = j;
		}
		else {
			largest = i;
		}
	}
	printf("Smallest: %d\n", smallest);
	printf("Largest: %d\n", largest);
	return 0;
}
