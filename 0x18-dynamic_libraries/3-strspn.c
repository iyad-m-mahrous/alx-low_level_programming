#include "main.h"

/**
 * _strspn - finds length of prefix substring
 *
 * @s: string to check
 * @accept: substring of chars
 *
 * Return: n bytes in intial segment of s which
 * consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int sum = 0;
	char *main_s = s;

	while (*accept != '\0')
	{
		while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
		{
			if (*s == *accept)
				sum++;
			s++;
		}

		accept++;
		s = main_s;
	}

	return (sum);
}
