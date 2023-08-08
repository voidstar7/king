#include <stdio.h>

// prompts user to enter numbers 1-16 in any order
// outputs numbers in a 4x4 square
// sums rows, columns, and diagonals

int main(void)
{
	int one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, rowOne, rowTwo, rowThree, rowFour, colOne, colTwo, colThree, colFour, diagRight, diagLeft;

	printf("Enter the numbers 1 to 16 in any order: ");

	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &one, &two, &three, &four, &five, &six, &seven, &eight, &nine, &ten, &eleven, &twelve, &thirteen, &fourteen, &fifteen, &sixteen);

	rowOne = one + two + three + four;
	rowTwo = five + six + seven + eight;
	rowThree = nine + ten + eleven + twelve;
	rowFour = thirteen + fourteen + fifteen + sixteen;

	colOne = one + five + nine + thirteen;
	colTwo = two + six + ten + fourteen;
	colThree = three + seven + eleven + fourteen;
	colFour = four + eight + twelve + sixteen; 

	diagRight = one + six + eleven + sixteen;
	diagLeft = four + seven + ten + thirteen;

	printf("%d %d %d %d\n %d %d %d %d\n %d %d %d %d\n %d %d %d %d\nRow sums: %d, %d, %d, %d\nColumn sums: %d, %d, %d, %d\nDiagonal sums: %d, %d\n", one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, rowOne, rowTwo, rowThree, rowFour, colOne, colTwo, colThree, colFour, diagRight, diagLeft);

	return 0;
}
