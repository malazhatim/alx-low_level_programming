#include "lists.h"

/**
 * get_nodeint_at_index - Node at a certain index in a linked list.
 * @head: First node.
 * @index: Index of the node.
 * Return: Pointer to the node otherwise NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int a = 0;

	if (head)
	{
		while (head)
		{
			if (a == index)
				return (head);
			head = head->next;
			a++;
		}
	}

	return (NULL);
}
