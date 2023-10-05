#include "hash_tables.h"

/**
 * hash_table_print - a function that prints a hash table.
 * @ht: the hash table
 *
 * Return: Void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t **v_temp, *h_temp;
	unsigned long int i, first = 0;

	if (!ht || ht->size == 0)
		return;
	v_temp = ht->array;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		h_temp = v_temp[i];
		if (v_temp[i])
		{
			if (first != 0)
			{
				printf(", ");
			}
			first = 1;
			printf("'%s': '%s'", v_temp[i]->key, v_temp[i]->value);
			while (h_temp->next)
			{
				h_temp = h_temp->next;
				printf(", '%s': '%s'", h_temp->key, h_temp->value);
			}
		}
	}
	printf("}\n");
}
