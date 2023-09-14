#include "lists.h"

/**
 * sum_dlistint - a function that returns the sum
 *  of all the data (n) of a dlistint
 * @head: list pointer
 *
 * Return:  the sum of all the data (n) or 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	const dlistint_t *ptr = head;

	while (ptr)
	{
		sum += ptr->n;
		ptr = ptr->next;
	}
	return (sum);
}
