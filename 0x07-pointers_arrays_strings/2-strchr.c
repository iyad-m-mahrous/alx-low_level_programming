#include "main.h"

/**
 * _strchr - finds if char occurs in string
 *
 * @s: string to check
 * @c: character to find in s
 *
 * Return: pointer to first instance of c, otherwise NULL
 */
char *_strchr(char *s, char c)
{
	while (*s != c && *s != '\0')
	{
		s++;
	}

	if (*s == c)
		return (s);

	return (NUL);
}
