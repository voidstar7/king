/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* inventory.c (Chapter 16, page 391) */
/* Maintains a parts database (array version) */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

typedef struct {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	double price;
} Part;

int sortOrder;
int maxParts = 3;

int find_part(Part *pi, int number, int num_parts);
int insert(Part *pi, int num_parts);
void search(Part *pi, int num_parts);
void update_quantity(Part *pi, int num_parts);
void update_price(Part *pi, int num_parts);
void print(Part *pi, int num_parts);
int compare_parts(const void *p, const void *q); 

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
	Part *inventory = malloc(sizeof(Part) * maxParts);
	if (inventory == NULL) {
		printf("Error: could not initialize inventory\n");
		free(inventory);
		return 1;
	}
	Part *pi = inventory;
	int num_parts = 0;
  char code;

	printf("Operation codes:\n"
		 "  'i': Insert\n"
		 "  's': Search\n"
		 "  'u': Update Quantity\n"
		 "  '$': Update Price\n"
		 "  'p': Print\n"
		 "  'q': Quit\n\n");

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': num_parts += insert(pi, num_parts);
                break;
      case 's': search(pi, num_parts);
                break;
      case 'u': update_quantity(pi, num_parts);
                break;
      case '$': update_price(pi, num_parts);
                break;
      case 'p': print(pi, num_parts);
                break;
      case 'q': free(inventory);
								return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            array. Returns the array index if the part  *
 *            number is found; otherwise, returns -1.     *
 **********************************************************/
int find_part(Part *pi, int number, int num_parts)
{
  int i;

  for (i = 0; i < num_parts; i++)
    if (pi[i].number == number)
      return i;
  return -1;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         database. Prints an error message and returns  *
 *         prematurely if the part already exists or the  *
 *         database is full.                              *
 **********************************************************/
int insert(Part *pi, int num_parts)
{
  int part_number;

  if (num_parts == maxParts) {
		Part *newPi;
    printf("Database is full (%d parts). Allocating space for 3 more parts\n", num_parts);
		newPi = realloc(pi, sizeof(Part) * maxParts); 
		if (newPi == NULL) {
			printf("Error: failed to reallocate memory\n");
			free(pi);
			exit(1);
		}
		if (pi == newPi)
			printf("Reallocated memory (%p) has same address as initial block (%p)\n\n", newPi, pi);
		else {
			printf("Address of reallocated memory (%p) was moved by realloc(). Old location (%p)\n\n", newPi, pi);
			pi = newPi;
			printf("Updated inventory array pointer to point to %p\n", newPi);
			// this breaks the program when printing after updating the pointer
		}
		maxParts += 3;
  }
  printf("Enter part number: ");
  scanf("%d", &part_number);
	if (num_parts > 0) {
		if (find_part(pi, part_number, num_parts) >= 0) {
			printf("Part already exists.\n");
			return 0;
		}
  }
  pi[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(pi[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &pi[num_parts].on_hand);
  printf("Enter price: ");
  scanf("%lf", &pi[num_parts].price);
	return 1;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(Part *pi, int num_parts)
{
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(pi, number, num_parts);
  if (i >= 0) {
    printf("Part name: %s\n", pi[i].name);
    printf("Quantity on hand: %d\n", pi[i].on_hand);
    printf("Price: $%lf\n", pi[i].price);
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update_quantity(Part *pi, int num_parts)
{
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(pi, number, num_parts);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    pi[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

// updates the price of a part
void update_price(Part *pi, int num_parts)
{
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(pi, number, num_parts);
  if (i >= 0) {
    printf("Enter new price: ");
    scanf("%lf", &pi[i].price);
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  
 *        showing the part number, part name, and         *
 *        quantity on hand. Parts are printed in the      *
 *        order in which they were entered into the       *
 *        database.                                       *
 **********************************************************/
void print(Part *pi, int num_parts)
{
	Part *p;

	printf("(1) sort ascending\n(2) sort descending: ");
	scanf("%d", &sortOrder);
	qsort(pi, num_parts, sizeof(Part), compare_parts);
  printf("Part Number   Part Name                Price         "
         "Quantity on Hand\n");
  for (
			p = pi;
			p < pi + num_parts; 
			p++)
				printf("%-14d%-25s$%-19.2lf%-11d %p\n", 
						p->number, 
						p->name, 
						p->price, 
						p->on_hand,
						p);
}

int compare_parts(const void *p, const void *q) {
	const Part *a = p, *b = q;

	if (sortOrder == 1) {
		if (a->number < b->number)
			return -1;
	}
	else {
		if (a->number > b->number)
			return -1;
	}
	if (a->number == b->number)
		return 0;
	else
		return 1;
}
