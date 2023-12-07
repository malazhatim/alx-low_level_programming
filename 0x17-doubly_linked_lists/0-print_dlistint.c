#include "lists.h"
/**
 * print_dlistint - prints length and elements
 * @h: head of list
 * Return: size_t value
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *t;
	int cou = 0;

	t = h;
	while (t != NULL)
	{
		printf("%d\n", t->n);
		t = t->next;
		cou++;
	}
	return (cou);
}
