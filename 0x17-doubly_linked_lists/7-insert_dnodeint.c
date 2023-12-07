#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node in a dlistint_t
 *                            list at a given position.
 * @h: A pointer to the head of the dlistint_t list.
 * @idx: The position to insert the new node.
 * @n: The integer for the new node to contain.
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *t = *h, *a;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		t = t->next;
		if (t == NULL)
			return (NULL);
	}

	if (t->next == NULL)
		return (add_dnodeint_end(h, n));

	a = malloc(sizeof(dlistint_t));
	if (a == NULL)
		return (NULL);

	a->n = n;
	a->prev = t;
	a->next = t->next;
	t->next->prev = a;
	t->next = a;

	return (a);
}
