#include "lists.h"

/**
 * free_dlistint - a function that frees a dlistint_t list.
 * @head: pointer to the list
 *
 * Return: None
 */
void free_dlistint(dlistint_t *head)
{
	if (head)
	{
		while (head)
		{
			if (head->next)
			{
				head = head->next;
				free(head->prev);
			}
			else
			{
				free(head);
				head = NULL;
			}
		}
	}
}
