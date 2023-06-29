#include "main.h"
/**
 * string_toupper - changes all lowercase letters of a string
 * to uppercase
 * @s: input string.
 * Return: the pointer to dest.
 */

char *string_toupper(char *s)
{
	char *main_string = s;
	while (*s != '\0')
	{
		if (*s >= 'a' && *s <= 'z')
			*s = *s + ('A' - 'a');
		s++;
	}

	return (main_string);

}
