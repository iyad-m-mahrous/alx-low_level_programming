#include "lists.h"

/**
 * find_listint_loop - finds a loop in a linked list
 *
 * @head: linked list to search
 *
 * Return: address of node where loop starts/returns, NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *node, *next;

	if (!head)
		return (NULL);

	node = head;
	next = head->next;

	while (next)
	{
		if (next == next->next)
			return (next);
		while (node != next)
		{
			if (node == next->next)
				return (node);
			node = node->next;
		}
		node = head;
		next = next->next;
	}
	return (NULL);
}
