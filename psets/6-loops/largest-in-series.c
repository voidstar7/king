#include <stdio.h>

// prompts the user to enter numbers one by one, then prints the largest of the series when 0 or a negative number are entered

int main(void) {
	float n, largest = 0;
	do {
		printf("Enter a number: "); 
		scanf("%f", &n);
		if (n > 0) {
			if (n > largest)
				largest = n;
			continue;
		}
		break;
	}
	while (n > 0);
	printf("The largest number entered was %g\n", largest);
}
