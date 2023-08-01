#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to head of singly linked list
 * @idx: index of the list where the new node should be added, starts at 0
 * @n: value that the node will have
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *prev, *new_n;
	unsigned int i = 0;

	if (idx > 0 && (*head) == NULL)
		return (NULL);
	new_n = malloc(sizeof(listint_t));
	if (!new_n)
		return (NULL);
	new_n->n = n;
	new_n->next = NULL;
	if (idx == 0 && (*head) == NULL)
	{
		(*head) = new_n;
		return (new_n);
	}

	prev = (*head);

	for (i = 0; i < (idx - 1); i++)
	{
		prev = prev->next;
	}

	if ((i + 1) < idx)
	{
		free(new_n);
		new_n = NULL;
		return (NULL);
	}
	new_n->next = prev->next;
	prev->next = new_n;
	return (new_n);

}
