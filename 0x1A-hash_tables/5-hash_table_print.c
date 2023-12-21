#include "hash_tables.h"

/**
 * hash_table_print - print hash table
 * @ht: hash table
 * Return: Printed hash table or nth
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int a;
	int init = 0;

	if (!ht)
		return;
	printf("{");
	for (a = 0; a <= ht->size; a++)
	{
		if (ht->array[a])
		{
			while (ht->array[a])
			{
				if (init != 0)
					printf(", ");
				printf("'%s': '%s'", ht->array[a]->key, ht->array[a]->value);
				init = 1;
				ht->array[a] = ht->array[a]->next;

			}
		}
	}
	printf("}\n");
}
