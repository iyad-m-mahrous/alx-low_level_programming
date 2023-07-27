#include "lists.h"

/**
 * add_node - Adds node to beginning of list
 * @head: Pointer to pointer to list
 * @str: String of new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	char *s;
	list_t *node;
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

	for (len = 0; s[len]; len++)
		;

	node->str = s;
	node->len = len;
	node->next = *head;
	*head = node;

	return (node);
}
