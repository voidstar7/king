#include <stdio.h>

// prompts for a number, then prints all even squares between 1 and the number
int main(void) {
	int n;
	printf("Enter a number: "); scanf("%d", &n);
	for (int i = 2; i * i <= n; i += 2) {
		printf("%d\n", i * i);
	}
}
