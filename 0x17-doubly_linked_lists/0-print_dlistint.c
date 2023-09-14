#include "lists.h"

/**
 * print_dlistint - a function that prints all the
 *  elements of a dlistint_t list
 * @h: list pointer
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t size = 0;
	const dlistint_t *ptr = h;

	if (!h)
		return (0);
	while (ptr)
	{
		printf("%i\n", ptr->n);
		size++;
		ptr = ptr->next;
	}
	return (size);
}
