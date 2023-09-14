#include "lists.h"

/**
 * add_dnodeint_end - a function that adds a new node at
 *  the end of a dlistint_t list.
 *  @head: pointer to the head
 *  @n: the value of the new node
 *
 *  Return:  the address of the new element,
 *   or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *ptr = *head;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (!ptr)
	{
		*head = new_node;
		new_node->prev = *head;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		new_node->prev = ptr;
		ptr->next = new_node;
	}
	return (new_node);
}
