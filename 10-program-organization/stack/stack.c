#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../19-program-design/adt/stackADT.h"

int main(void) {
	Stack s = create();
	char input;
	printf("Enter parentheses and/or braces: ");
	while (input != '\x0a') {
		scanf("%c", &input);
		if (input == '{' || input == '(') {
			push(s, input);	
			printf("Pushed %c\n", input);
		}
		else if (input == '}' || input == ')') {
			pop(s);
			printf("Popped %c\n", input);
		}
	}
	if (!is_empty(s))
		terminate("Parentheses/braces are NOT nested correctly");
	else {
		printf("Parentheses/braces are nested correctly\n");
		return 0;
	}
}
