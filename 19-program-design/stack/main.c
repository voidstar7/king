#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

Node *s1 = NULL;

int main(void) {
	push(&s1, 3);
	push(&s1, 8);
	push(&s1, 5);
	push(&s1, 2);
	push(&s1, 1);
	pop(&s1);
	pop(&s1);
	pop(&s1);
	pop(&s1);
	pop(&s1);
	push(&s1, 82);
	push(&s1, 22);
	push(&s1, 19);
	pop(&s1);
	pop(&s1);
	pop(&s1);
	pop(&s1); // throws empty error
}
