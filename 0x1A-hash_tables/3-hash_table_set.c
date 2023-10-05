#include "hash_tables.h"

/**
 * hash_table_set -  function that adds an element to the hash table.
 * @ht: is the hash table you want to add or update the key/value to
 * @key: is the key. key can not be an empty string
 * @value: is the value associated with the key.
 *  value must be duplicated. value can be an empty string
 *
 *  Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;
	char *key_dup, *value_dup;

	if (!(ht) || !key || !key[0] || ht->size == 0 || !ht->array)
		return (0);
	key_dup = strdup(key);
	if (!key_dup)
		return (0);
	value_dup = strdup(value);
	if (!value_dup)
	{
		free(key_dup);
		return (0);
	}
	new_node = (hash_node_t *) calloc(1, sizeof(*new_node));
	if (!new_node)
		return (free(key_dup), free(value_dup), 0);
	new_node->key = key_dup;
	new_node->value = value_dup;

	index = key_index((unsigned char *)key, ht->size);
	if (!ht->array[index])
		ht->array[index] = new_node;
	else if (strcmp(ht->array[index]->key, key))
	{
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}
	else
	{
		free(ht->array[index]->value);
		ht->array[index]->value = value_dup;
		free(key_dup);
		free(new_node);
	}
	return (1);
}
