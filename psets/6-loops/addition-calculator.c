#include <stdio.h>

int main(void) {
	int n, sum = 0;
	printf("Enter numbers to compute their sum (0 to exit): ");
	do {
		scanf("%d", &n);
		sum += n;
	}
	while (n != 0);
	printf("The sum is %d\n", sum);
}
