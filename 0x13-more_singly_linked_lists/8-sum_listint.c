#include "lists.h"

/**
* sum_listint - Sum the data (n) in list.
* @head: Pointer to the list head.
* Return: Sum of data otherwise 0.
**/
int sum_listint(listint_t *head)
{
	int a = 0;

		while (head != NULL)
		{
			a += head->n;
			head = head->next;
		}

	return (a);
}
