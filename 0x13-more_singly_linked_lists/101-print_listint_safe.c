#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a singly linked list (can print lists with loop)
 * @head: head pointer of singly linked list
 *
 * Return: Number of elements in list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *temp = head;
	int size = 0;

	if (!head)
		return (0);
	if (!head->next)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		return (1);
	}
	while (temp)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		size++;
		if (temp->next > temp)
		{
			temp = temp->next;
			printf("-> [%p] %d\n", (void *)temp, temp->n);
			break;
		}
		temp = temp->next;
	}
	return (size);

}
