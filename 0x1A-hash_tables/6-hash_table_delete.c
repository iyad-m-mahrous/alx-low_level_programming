#include "hash_tables.h"

/**
 * hash_table_delet - a function that deletes a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp, *h_temp;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{

		h_temp = ht->array[i];
		while (h_temp)
		{
			temp = h_temp->next;
			free(h_temp->key);
			free(h_temp->value);
			free(h_temp);
			h_temp = temp;
		}
	}
	free(ht->array);
	free(ht);
}
