#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: A pointer to the head of the dlistint_t list.
 * @n: The integer for the new node to contain.
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *a, *h;

	a = malloc(sizeof(dlistint_t));
	if (a == NULL)
		return (NULL);

	a->n = n;
	a->next = NULL;

	if (*head == NULL)
	{
		a->prev = NULL;
		*head = a;
		return (a);
	}

	h = *head;
	while (h->next != NULL)
		h = h->next;
	h->next = a;
	a->prev = h;

	return (a);
}
