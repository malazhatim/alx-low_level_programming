#include "lists.h"

/**
 * print_listint_safe - function that prints a linked list with a loop safely.
 * @head: pointer to the 1st node of the linked list
 * Return: new_node
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *t = NULL;
	const listint_t *n = NULL;
	size_t c = 0;
	size_t new;

	t = head;
	while (t)
	{
		printf("[%p] %d\n", (void *)t, t->n);
		c++;
		t = t->next;
		n = head;
		new = 0;
		while (new < c)
		{
			if (t == n)
			{
				printf("-> [%p] %d\n", (void *)t, t->n);
				return (c);
			}
			n = n->next;
			new++;
		}
		if (!head)
			exit(98);
	}
	return (c);
}
