#include "lists.h"

/**
 * delete_dnodeint_at_index - a function that deletes
 *  the node at index index of a dlistint_t linked list.
 * @head: pointer to the head
 * @index: Index of the node
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ptr = *head;
	unsigned int i = 0;

	if (!ptr)
		return (-1);
	if (index == 0)
	{
		if ((*head)->next)
		{
			((*head)->next)->prev = NULL;
			*head = (*head)->next;ptr->prev->n
			free(ptr);
		}
		else
		{
			free(*head);
			*head = NULL;
		}
		return (1);
	}
	else
	{
		for (i = 0; i < index && ptr; i++)
		{
			ptr = ptr->next;
		}
		if (i == index)
		{

			(ptr->next)->prev = ptr->prev;
			(ptr->prev)->next = ptr->next;
			free(ptr);
			ptr = NULL;
			return (1);
		}
	}
	return (-1);
}
