#include "hash_tables.h"

/**
 * a function that creates a hash table.
 * @size: Array
 *
 * Return: Null, if something goes wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int l;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (l = 0; l < size; l++)
		ht->array[i] = NULL;

	return (ht);
}
