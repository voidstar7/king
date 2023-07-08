#include <stdio.h>

// prompts the user to enter numbers one by one, then prints the largest of the series when 0 or a negative number are entered

int main(void) {
	int n, largest = 0;
	do {
		printf("Enter a number: "); 
		scanf("%d", &n);
		if (n > 0) {
			if (n > largest)
				largest = n;
			continue;
		}
		else
			break;
	}
	while (n > 0);
	printf("The largest number entered was %d\n", largest);
	return 0;
}
