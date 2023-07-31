#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints a singly linked list
 * @h: pointer to head of singly linked list
 *
 * Return: Number of elements in list
 */
size_t print_listint(const listint_t *h)
{
	if (!h)
		return (0);
	printf("%d\n", h->n);
	h = h->next;
	return (print_listint(h) + 1);
}
