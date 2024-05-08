#include "search_algos.h"

/**
 * jump_list - Searches for an algorithm in a sorted singly
 *             linked list of integers using jump search.
 * @list: A pointer to the  head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for
 * Return: If the value is not present or the head of the list is NULL, NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t s, s_size;
	listint_t *o, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	s = 0;
	s_size = sqrt(size);
	for (o = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		o = jump;
		for (s += s_size; jump->index < s; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			o->index, jump->index);

	for (; o->index < jump->index && o->n < value; o = o->next)
		printf("Value checked at index [%ld] = [%d]\n", o->index, o->n);
	printf("Value checked at index [%ld] = [%d]\n", o->index, o->n);

	return (o->n == value ? o : NULL);
}
