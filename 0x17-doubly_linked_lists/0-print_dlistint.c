#include "lists.h"

/**
 * print_dlistint - print element in list
 * @h:struct list
 * Return:list len
 */
size_t print_dlistint(const dlistint_t *h)
{
	int a;
	size_t l = 0;

	for (a = 0; h; a++)
	{
		printf("%d\n", h->n);
		h = h->next;
		b++;
	}
	return (b);
}
