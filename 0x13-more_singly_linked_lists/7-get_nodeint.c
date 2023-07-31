#include "lists.h"

/**
 * get_nodeint_at_index -  returns the nth node of a listint_t linked list
 * @head: head pointer of singly linked list
 * @index: index to find in list
 *
 * Return: nth node of a listint_t linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp;
	unsigned int i = 0;

	temp = head;
		
	for (i = 0; i < index; i++)
	{
		if (!temp)
			return (NULL);
		temp = temp->next;
	}
	return (temp);
}
