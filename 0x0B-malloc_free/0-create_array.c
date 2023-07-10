#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - returns a pointer to aan array of chars
 * @size: size of the array
 * @c: the initialluzation charater
 *
 * Return: Pointer
 */

char *create_array(unsigned int size, char c)
{
	char *new_string;
	unsigned int i;

	if (size == 0)
	{
		return (0);
	}
	new_string = (char *) malloc(sizeof(char) * size);

	if (new_string)
	{
		for (i = 0; i < size; i++)
		{
			new_string[i] = c;
		}
	}
	else
	{
		return (0);
	}

	return (new_string);
}
