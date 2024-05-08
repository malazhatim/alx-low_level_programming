#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 * @a: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 */
typedef struct skiplist_s
{
				int a;
				size_t index;
				struct skiplist_s *next;
				struct skiplist_s *express;
} skiplist_t;

/**
 * struct listint_s - singly linked list
 * @i: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 */
typedef struct listint_s
{
		int i;
		size_t index;
		struct listint_s *next;
} listint_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);
#endif
