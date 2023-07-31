#include "lists.h"

/**
 * free_listint2 - frees memory of a list
 * @head: pointer to head of singly linked list
 *
 * Return: No Return
 */
void free_listint2(listint_t **head)
{
	listint_t *temp = *head;

	if (!(*head))
		return;
	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
		free(temp);
		temp = (*head);
	}

	free(temp);
	temp = NULL;
	free(*head);
	*head = NULL;
}
