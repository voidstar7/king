#include <stdio.h>

// uses a switch statement to assign a letter grade to a score
int main(void) {
	int score, digitOne;
	printf("Enter your score (out of 100): "); scanf("%d", &score);
	digitOne = score / 10;
	if (score < 0 || score > 100)
		printf("Error\n");
	 else if (score == 100)
		 printf("A\n");
	else 
		switch (digitOne) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5: printf("F\n");
							break;
			case 6: printf("D\n");
							break;
			case 7: printf("C\n");
							break;
			case 8: printf("B\n");
							break;
			case 9: printf("A\n");
							break;
		}
}
