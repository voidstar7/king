#include <stdio.h>

// asks for a dollars and cents amount then calculates and displays total with 5% tax added

int main(void)
{
	float amount;
	printf("Enter an amount: ");
	scanf("%f", &amount);

	float taxRate = 0.05;
	printf("With tax added: %.2f\n", amount * (1 + taxRate));
}
