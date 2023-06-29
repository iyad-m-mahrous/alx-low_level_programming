#include "main.h"
/**
 * leet - encodes a string into 1337
 * @s: input string.
 * Return: the pointer to dest.
 */

char *leet(char *s)
{
	char *main_string = s;
	int i;
	char lower[] = {'a', 'e', 'o', 't', 'l'};
	char upper[] = {'A', 'E', 'O', 'T', 'L'};
	int result[] = {'4', '3', '0', '7', '1'};
	
	while (*s != '\0')
	{
		for (i = 0; i < 5; i++)
		{
			if (*s == lower[i] || *s == upper[i])
			{
				*s = result[i];
			}
		}

		s++;		
	}

	return (main_string);
}
