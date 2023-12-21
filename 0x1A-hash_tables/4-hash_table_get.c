#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: hash table
 * @key: key
 * Return: Value associeted with the key or Null
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int in;
	hash_node_t *no;

	if (!ht || !key)
		return (NULL);
	in = key_index((const unsigned char *)key, ht->size);
	no = ht->array[index];
	while (no)
	{
		if (strcmp(no->key, key) == 0)
			return (no->value);
		no = no->next;
	}
	return (NULL);
}
