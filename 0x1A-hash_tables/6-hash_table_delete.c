#include "hash_tables.h"

/**
 * hash_table_delete - delete a hash table
 * @ht:hash table
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *nod;

	if (!ht || !ht->array || !ht->size)
		return;
	for (a = 0; a < ht->size; a++)
	{
		while (ht->array[a])
		{
			nod = ht->array[a]->next;
			free(ht->array[a]->key);
			free(ht->array[a]->value);
			free(ht->array[a]);
			ht->array[a] = nod;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
