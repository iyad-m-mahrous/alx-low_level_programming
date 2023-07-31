#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to head of singly linked list
 *
 * Return: head node’s data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (!(*head))
		return (0);

	temp = *head;
	n = temp->n;
	*head = (*head)->next;
	free(temp);
	return (n);
}
