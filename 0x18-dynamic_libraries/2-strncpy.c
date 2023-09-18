#include "main.h"
/**
 * _strncpy - copies a string
 * @dest: destination.
 * @src: source.
 * @n: amount of bytes from src.
 * Return: the pointer to dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	char *main_dest = dest;
	int i, j;

	for (i = 0; i < n; i++)
	{
		*dest = src[i];
		dest++;
		if (src[i] == '\0')
		{
			for (j = 1; j < (n - i); j++)
			{
				*dest = '\0';
				dest++;
			}
			break;
		}
	}

	return (main_dest);
}
