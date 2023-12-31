#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: Pointer
 */

char *str_concat(char *s1, char *s2)
{
	int size1 = 0, size2 = 0, i;
	char *new;

	if (s1)
	{
		for (i = 0; s1[i] != '\0'; i++)
			size1++;
	}
	if (s2)
	{
		for (i = 0; s2[i] != '\0'; i++)
			size2++;
	}
	new = (char *) malloc(sizeof(char) * (size1 + size2 + 1));

	if (!new)
		return (0);
	if (!(size1 + size2))
	{
		*new = '\0';
		return (new);
	}

	for (i = 0; i < size1; i++)
	{
		new[i] = s1[i];
	}
	for (i = 0; i < size2; i++)
	{
		new[i + size1] = s2[i];
	}
	new[size1 + size2] = '\0';
	return (new);
}
