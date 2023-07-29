#include <stdio.h>

// add, subtract, multiply, or divide two fractions

int main (void)
{
	int n1, d1, n2, d2, n3, d3;
	char op;
	printf("Enter two fractions separated by an operator: ");
	scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
	switch(op)
	{
		case '+':
			if (d1 == d2)
			{
				n3 = n1 + n2;
				d3 = d1;
				break;
			}
			n3 = (n1 * d2) + (n2 * d1);
			d3 = d1 * d2;
			break;
		case '-':
			if (d1 == d2)
			{
				n3 = n1 - n2;
				d3 = d1;
				break;
			}
			n3 = (n1 * d2) - (n2 * d1);
			d3 = d1 * d2;
			break;
		case '*':
			n3 = n1 * n2;
			d3 = d1 * d2;
		case '/':
			n3 = n1 * d2;
			d3 = d1 * n2;
			break;
	}
	printf("%d/%d", n3, d3);
	return 0;
}
