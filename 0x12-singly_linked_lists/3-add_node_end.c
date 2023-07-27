#include "lists.h"

/**
 * add_node_end - Adds node to end of list
 * @head: Pointer to pointer to list
 * @str: string of new node
 *
 * Return: adress of new node,
 * or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	char *s;
	list_t *node;
	list_t *ptr;
	size_t len;

	node = malloc(sizeof(list_t));
	if (!node)
		return (NULL);

	s = strdup(str);
	if (!s)
	{
		free(node);
		return (NULL);
	}

	for (len = 0; str[len]; len++)
		;

	node->str = s;
	node->len = len;
	node->next = NULL;

	if (!(*head))
	{
		*head = node;
		return (node);
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = node;

	return (node);
}
