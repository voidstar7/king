#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *s1, *s2;

int main(void) {
	push(&s1, 72);
	push(&s2, 22);
	push(&s2, 288);
	push(&s2, 888);
	push(&s1, 88);
	push(&s1, 92);
	push(&s1, 18);
	print_stack(&s1);
	print_stack(&s2);
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
