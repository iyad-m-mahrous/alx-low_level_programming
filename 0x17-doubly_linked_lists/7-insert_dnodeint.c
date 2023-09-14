#include "lists.h"

/**
 * insert_dnodeint_at_index - a function that inserts
 * a new node at a given position.
 * @h: pointer to the head
 * @idx: Index of the new node
 * @n: value of the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *ptr = *h;
	unsigned int i = 0;

	if (!ptr)
		return (NULL);
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (idx == 0)
	{
		*h = new_node;
		new_node->prev = *h;
	}
	else
	{
		for (i = 0; i < idx && ptr; i++)
		{
			ptr = ptr->next;
		}
		if (i == idx)
		{
			new_node->prev = ptr->prev;
			new_node->next = ptr;
			(ptr->prev)->next = new_node;
			ptr->prev = new_node;
		}
		else if (i == (idx - 1))
		{
			ptr->next = new_node;
			new_node->prev = ptr;
		}
		else
		{
			return (NULL);
		}
	}
	return (new_node);
}
