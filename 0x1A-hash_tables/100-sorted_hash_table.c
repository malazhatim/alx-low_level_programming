#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the hash table
 * Return: pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int a;
	shash_table_t *s;

	if (size == 0)
		return (NULL);
	s = malloc(sizeof(shash_table_t));
	if (!s)
		return (NULL);
	s->size = size;
	s->array = malloc(sizeof(shash_node_t *) * size);
	if (!(sht->array))
	{
		free(s);
		return (NULL);
	}
	for (a = 0; a < size; a++)
		s->array[a] = NULL;
	s->shead = s->stail = NULL;
	return (s);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *s;

	s = malloc(sizeof(shash_node_t));
	if (s == NULL)
		return (NULL);
	s->key = strdup(key);
	if (s->key == NULL)
	{
		free(s);
		return (NULL);
	}
	s->value = strdup(value);
	if (s->value == NULL)
	{
		free(s->key);
		free(s);
		return (NULL);
	}
	s->next = s->snext = s->sprev = NULL;
	return (s);
}

/**
 * add_node - add a node
 * @table: the sorted hash table
 * @node: the node to add
 * Return: void
 */
void add_node(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *t;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	t = table->shead;
	while (t != NULL)
	{
		if (strcmp(node->key, t->key) < 0)
		{
			node->snext = t;
			node->sprev = t->sprev;
			t->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		t = t->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	shash_node_t *shn, *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}
	shn = make_shash_node(key, value);
	if (shn == NULL)
		return (0);
	shn->next = ht->array[index];
	ht->array[index] = shn;
	add_node(ht, shn);
	return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: hash table
 * @key: key to the data
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmp = ht->shead;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int a;
	shash_node_t *n;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (a = 0; a < ht->size; a++)
	{
		while (ht->array[a] != NULL)
		{
			n = ht->array[a]->next;
			free(ht->array[a]->key);
			free(ht->array[a]->value);
			free(ht->array[a]);
			ht->array[a] = n;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
