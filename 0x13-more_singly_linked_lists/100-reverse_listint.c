#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to head of singly linked list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next_n, *temp;

	if (!(*head))
		return (NULL);
	if (!((*head)->next))
		return (*head);
	next_n = (*head)->next;
	temp = *head;
	(*head)->next = NULL;
	while (next_n)
	{
		temp = next_n;
		next_n = next_n->next;
		temp->next = *head;
		*head = temp;
	}

	return (*head);
}
