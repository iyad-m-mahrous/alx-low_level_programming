#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list.
 * @h: Pointer to the list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t n;
	const list_t *ptr;

	ptr = h;
	n = 0;
	while (ptr != NULL)
	{
		if (ptr->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", ptr->len, ptr->str);
		n++;
		ptr = ptr->next;
	}
	return (n);
}
