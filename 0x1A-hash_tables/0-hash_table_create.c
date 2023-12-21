#include "hash_tables.h"

/**
 * hash_table_create - Create a Hash Table
 * @size: The size of the hash  table
 * Descreption : Alloctaing a Hash Table using Given Size
 * Return: NULL Error Occurred Or A Hash Table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *h_table;

	h_table = malloc(sizeof(hash_table_t));
	if (h_table == NULL)
		return (NULL);
	h_table->size = size;
	h_table->array = malloc(sizeof(h_table->array) * size);
	if (h_table->array == NULL)
		return (NULL);
	return (h_table);
}
