#include "hash_tables.h"

/**
 * hash_table_create - a function that creates a hash table.
 * @size:  is the size of the array
 *
 * Return: Returns a pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *h_table;

	if (size == 0)
		return (NULL);
	h_table = (hash_table_t *) malloc(sizeof(*h_table) * 1);
	if (!h_table)
		return (NULL);

	h_table->size = size;
	h_table->array = (hash_node_t **) calloc(size, sizeof(*(h_table->array)));
	if (!(h_table->array))
	{
		free(h_table);
		return (NULL);
	}

	return (h_table);
}
