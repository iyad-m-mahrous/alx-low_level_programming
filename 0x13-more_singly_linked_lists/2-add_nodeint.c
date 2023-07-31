#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a singly linked list
 * @head: pointer to head of singly linked list
 * @n: number to add as new node in the list
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}
