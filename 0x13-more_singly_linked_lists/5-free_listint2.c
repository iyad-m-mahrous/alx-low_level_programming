#include "lists.h"

/**
 * free_listint2 - frees memory of a list
 * @head: pointer to head of singly linked list
 *
 * Return: No Return
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!(*head->next))
	{
		free(*head);
		head = NULL;
		return;
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
	free_listint2(head);
}
