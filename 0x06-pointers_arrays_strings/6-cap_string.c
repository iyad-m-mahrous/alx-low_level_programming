#include "main.h"
/**
 * cap_string - capitalizes all words of a string
 * @s: input string.
 * Return: the pointer to dest.
 */

char *cap_string(char *s)
{
	char *main_string = s;

	while (*s != '\0')
	{
		if (*s >= 'a' && *s <= 'z')
		{
			if (s == main_string)
			{
				*s = *s + ('A' - 'a');
			}
			else if (*(s - 1) == ' ' || *(s - 1) == '.'
					|| *(s - 1) == '\n' || *(s - 1) == ','
					|| *(s - 1) == ';' || *(s - 1) == '!'
					|| *(s - 1) == '?' || *(s - 1) == '"'
					|| *(s - 1) == '(' || *(s - 1) == ')'
					|| *(s - 1) == '{' || *(s - 1) == '}'
					|| *(s - 1) == '\t')
			{
				*s = *s + ('A' - 'a');
			}

		}
	}

	return (main_string);
}
