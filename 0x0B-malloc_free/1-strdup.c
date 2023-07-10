#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 * @str: string to copy
 *
 * Return: Pointer
 */

char *_strdup(char *str)
{
	char *new;
	unsigned int i, size = 0;

	if (!str)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
		size++;

	new = (char *) malloc(sizeof(char) * (size + 1));
	if (!new)
	{
		return (0);
	}

	for (i = 0; i < size; i++)
	{
		new[i] = str[i];
	}
	new[size] = '\0';

	return (new);

}
