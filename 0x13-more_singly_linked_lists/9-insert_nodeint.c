#include "lists.h"
#include <stdio.h>

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
	listint_t *temp = *head, *new;
	unsigned int i = 0;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;

	while (temp && (i < (idx - 1)))
	{
		i++;
		temp = temp->next;

	}
	
	if (i == (idx - 1))
	{
		new->next = temp->next;
		temp->next = new;
		return (new);
	}
	else
		return (NULL);

}
