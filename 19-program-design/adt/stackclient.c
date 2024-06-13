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
#include "stackADT2.h"

int main(void)
{
  Stack s1;
  s1 = create(5);

  push(s1, 1);
  push(s1, 1);
  push(s1, 1);
  push(s1, 1);
  push(s1, 1); // full
	printf("%d\n", peek(s1));
  push(s1, 2);
  push(s1, 2);
  push(s1, 2);
  push(s1, 2);
  push(s1, 2); // full
	printf("%d\n", peek(s1));
  push(s1, 3);
  push(s1, 3);
  push(s1, 3);
  push(s1, 3);
  push(s1, 3); // full
	printf("%d\n", peek(s1));
  return 0;
}
