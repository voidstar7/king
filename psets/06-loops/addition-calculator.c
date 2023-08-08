#include <stdio.h>

int main(void) {
	int i, n = 0, sum = 0;
	printf("Enter up to 10 numbers except 4 to compute their sum (press 0 to exit): ");
	while (n < 10) {
		scanf("%d", &i);
		if (i == 4) {
			printf("Invalid number!\n");
			continue;
		}
		else if (i == 0) {
			printf("Exiting\n");
			goto exit;
		}
		sum += i;
		n++;
	}
	exit:
	printf("The sum is %d\n", sum);
}
