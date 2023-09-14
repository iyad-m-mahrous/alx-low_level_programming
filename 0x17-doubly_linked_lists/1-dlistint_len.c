#include "lists.h"

/**
 * dlistint_len - a function that returns the
 *  number of elements in a linked dlistint_t list
 * @h: list pointer
 *
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t size = 0;
	const dlistint_t *ptr = h;

	if (!h)
		return (0);
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
