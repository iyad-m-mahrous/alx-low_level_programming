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
	size_t size = 0;

	if (!head)
		return (size);
	while (temp)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		size++;
		if (temp->next >= temp)
		{
			temp = temp->next;
			printf("-> [%p] %d\n", (void *)temp, temp->n);
			exit(98);
			break;
		}
		temp = temp->next;
	}
	return (size);

}
