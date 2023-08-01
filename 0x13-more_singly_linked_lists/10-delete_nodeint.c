#include "lists.h"
#include <stdio.h>

/**
 * delete_nodeint_at_index - deletes the node at index index of
 * a listint_t linked list
 * @head: pointer to head of singly linked list
 * @index: index of the list where we want to delete a node
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node = *head, *prev = NULL;
	unsigned int i = 0;

	if (!(*head))
		return (-1);
	for (i = 0; i < index; i++)
	{
		prev = node;
		node = node->next;
		if (!node)
		{
			return (-1);
		}
	}
	if (prev)
	{
		prev->next = node->next;
	}
	else
	{
		*head = node->next;

		if (!(*head))
		{
			free(*head);
			free(node);
			(*head) = NULL;
			return (1);
		}
	}
	free(node);
	return (1);
}
