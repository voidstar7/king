#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *s1;

int main(void) {
	push(&s1, 72);
	//print_stack(&s1);
	/*
	make_empty(s1);
	push(s1, 8);
	printf("pushed 8\n");
	push(s1, 2);
	printf("pushed 2\n");
	printf("%d %d\n", 
			s1->contents[0], 
			s1->contents[1]);
	printf("popped %d\n", pop(s1));
	printf("popped %d\n", pop(s1));
	pop(s1);
	*/
}
