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
 * print_listint_safe - prints a singly linked list (can print lists with loop)
 * @head: head pointer of singly linked list
 *
 * Return: Number of elements in list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *temp = head;
	size_t size = 0;
	listint_t *looped = find_listint_loop((listint_t *)head);
	int is_looped = 0;

	if (!head)
		return (size);

	while (temp)
	{
		if (temp == looped)
			is_looped = 1;
		printf("[%p] %d\n", (void *)temp, temp->n);
		size++;
		if (looped == temp->next && is_looped)
		{
			temp = temp->next;
			printf("-> [%p] %d\n", (void *)temp, temp->n);
			break;
		}
		temp = temp->next;
	}
	return (size);

}
