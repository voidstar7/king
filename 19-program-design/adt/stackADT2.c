/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackADT2.c (Chapter 19, page 498) */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"
#include <ctype.h>
#include <string.h>

struct stack_type {
  Item *contents;
  int top;
  int size;
};

int evaluate_expression(const char *expression)
{
	Stack s = create(5);
	char *p = (char *)expression;
	while (*p)
	{
		if (isdigit(*p))
		{
			push(s, *p - '0');
			p++;
		}
		else if (ispunct(*p))
		{
			int temp;
			switch (*p)
			{
				case '+':
					{
						temp = 
							(s->contents[(s->top) - 2]) + 
							(s->contents[(s->top) - 1]);
						pop(s); pop(s);
						push(s, temp);
						break;
					}
				case '-':
					{
						temp = 
							(s->contents[(s->top) - 2]) - 
							(s->contents[(s->top) - 1]);
						pop(s); pop(s);
						push(s, temp);
						break;
					}
				case '*':
					{
						temp = 
							(s->contents[(s->top) - 2]) * 
							(s->contents[(s->top) - 1]);
						pop(s); pop(s);
						push(s, temp);
						break;
					}
				case '/':
					{
						temp = 
							(s->contents[(s->top) - 2]) / 
							(s->contents[(s->top) - 1]);
						pop(s); pop(s);
						push(s, temp);
						break;
					}
				default:
					exit(EXIT_FAILURE);
			}
		}
		p++;
	}
	return s->contents[0];
}

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(int size)
{
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->contents = malloc(size * sizeof(Item));
  if (s->contents == NULL) {
    free(s);
    terminate("Error in create: stack could not be created.");
  }
  s->top = 0;
  s->size = size;
  return s;
}

void destroy(Stack s)
{
  free(s->contents);
  free(s);
}

void make_empty(Stack s)
{
  s->top = 0;
}

bool is_empty(Stack s)
{
  return s->top == 0;
}

bool is_full(Stack s)
{
  return s->top == s->size;
}

void push(Stack s, Item i)
{
  if (is_full(s)) {
		printf("Stack is full. Doubling size\n");
		int newSize = s->size * 2;
		Item *tmp = realloc(s->contents, sizeof(Item) * newSize);
		if (tmp == NULL) 
			terminate("Could not reallocate memory\n");
		s->contents = tmp;
		s->size = newSize;
	}
	s->contents[s->top++] = i;
}

Item pop(Stack s)
{
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");
  return s->contents[--s->top];
}

Item peek(Stack s) {
	if (is_empty(s))
		terminate("Error in peek: stack is empty\n");
	return s->contents[s->top - 1];
}
