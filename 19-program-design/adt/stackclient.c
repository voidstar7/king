/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackclient.c (Chapter 19, page 494) */

#include <stdio.h>
#include "stackADT.h"

int main(void)
{
  Stack s1, s2;
  s1 = create();
  s2 = create();
	
	char input1[] = "Hello";
	char input2[] = "world";
	char input3[] = "Dog";
	char input4[] = "Cat";
	push(s1, input1);
	push(s1, input2);
	push(s2, input3);
	push(s2, input4);
	printf("%s\n", (char *)peek(s1));
	printf("%s\n", (char *)peek(s2));
	pop(s1);
	pop(s2);
	printf("%s\n", (char *)peek(s1));
	printf("%s\n", (char *)peek(s2));
  return 0;
}
