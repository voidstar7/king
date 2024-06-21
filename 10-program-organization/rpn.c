#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../19-program-design/adt/stackADT2.h"

#define MAX_INPUT 50

// a RPC calculator that accepts single digit operands

char expression[MAX_INPUT];

int main(void)
{
	printf(">>> ");
	fgets(expression, MAX_INPUT, stdin);
	printf("%d\n", evaluate_expression(expression));
}
