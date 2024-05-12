#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

Node *s1;

int main(void) {
	s1 = createStack(s1);
	initialize(s1);
	push(s1, 3);
	push(s1, 8);
	push(s1, 5);
	//printf("Popped %i\n", pop(s1));
	//printf("Popped %i\n", pop(s1));
	//printf("Popped %i\n", pop(s1));
}
