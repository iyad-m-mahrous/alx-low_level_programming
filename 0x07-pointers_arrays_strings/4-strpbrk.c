#include "main.h"

/**
 * _strpbrk - searches string for set of bytes
 *
 * @s: string to check
 * @accept: substring of chars
 *
 * Return: pointer to first occurance
 */
char *_strpbrk(char *s, char *accept)
{
	char *main_accept = accept;

	while (*s != '\0')
	{
		while (*accept != '\0')
		{
			if (*s == *accept)
				return (s);
			accept++;
		}
		accept = main_accept;
		s++;
	}

	return (NULL);
}
