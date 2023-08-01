#include <stdio.h>
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

/**
 * free_listint_safe - frees a listint_t list (can free lists with a loop)
 * @h: pointer to head of singly linked list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp = *h, *to_del, *looped;
	size_t size = 0;
	int passed_loop = 0;

	if (!*h || !h)
		return (size);
	looped = find_listint_loop(*h);
	while (temp)
	{
		if (temp == looped)
			passed_loop = 1;
		to_del = temp;
		temp = to_del->next;
		free(to_del);
		size++;

		if (!temp)
		{
			break;
		}
		if (temp->next == looped && passed_loop)
		{
			free(temp);
			size++;
			break;
		}
	}
	*h = NULL;
	return (size);
}
