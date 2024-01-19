#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int g(int i);

int main(void) {
	int i, j;

	printf("start: "); scanf("%d", &i);
	printf("end: "); scanf("%d", &j);
	printf("%d\n", sum(g, i, j));
	return 0;
}

// sums the numbers between start and end (inclusive)
int sum(int (*f)(int), int start, int end) { 
	int total = start;

	while (start < end)
		total += g(start++);
	return total;
}

int g(int i) {
	return i + 1;
}
