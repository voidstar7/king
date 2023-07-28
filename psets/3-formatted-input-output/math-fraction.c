#include <stdio.h>

// add, subtract, multiply, or divide two fractions

int main (void)
{
	int n1, d1, n2, d2;
	char op;

	printf("Enter two fractions separated by an operator: ");
	scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);

	return 0;
}
