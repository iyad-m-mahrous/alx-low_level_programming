#include "lists.h"

/**
 * get_dnodeint_at_index - a function that returns
 *  the nth node of a dlistint_t linked list
 *  @head: linked list head pointer
 *  @index: is the index of the node, starting from 0
 *
 *  Return: nth node or NULL if not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *ptr = head;
	unsigned int i = 0;

	if (ptr)
	{
		for (i = 0; i < index && ptr; i++)
		{
			ptr = ptr->next;
		}
		if (i == index)
			return (ptr);
	}
	return (NULL);
}
