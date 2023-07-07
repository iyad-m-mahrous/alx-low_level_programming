#include "main.h"
/**
 * rot13 - encodes a string using rot13
 * @s: input string.
 * Return: the pointer to dest.
 */

char *rot13(char *s)
{
	char *main_string = s;
	char A_or_a;

	while (*s != '\0')
	{
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
		{
			A_or_a = (*s & 32) + 'A';
			*s = ((*s - A_or_a + 13) % 26) + A_or_a;
		}
		s++;
	}

	return (main_string);
}
