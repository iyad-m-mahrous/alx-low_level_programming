#include "lists.h"

/**
 * list_len - Returns length of list
 * @h: Pointer to list
 *
 * Return: Length of list
 */
size_t list_len(const list_t *h)
{
	size_t n;
	const list_t *ptr;

	ptr = h;
	n = 0;
	while (ptr != NULL)
	{
		n++;
		ptr = ptr->next;
	}
	return (n);
}
