#include <stdio.h>

// prompts for a digit number, then prints the number reversed
int main(void) {
	int n, r;
	printf("Enter a number: ");
	scanf("%d", &n);
	do {
		printf("%d", n % 10);		
		n /= 10;
	}
	while (n != 0);
	printf("\n");
	return 0;
}
