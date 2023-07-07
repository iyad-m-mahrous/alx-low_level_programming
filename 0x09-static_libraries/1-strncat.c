#include "main.h"
/**
 * _strncat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 * @n: amount of bytes used from src.
 *
 * Return: the pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *main_dest = dest;
	int i;

	while (*dest != '\0')
		dest++;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		*dest = src[i];
		dest++;
	}

	*(dest) = '\0';
	return (main_dest);
}
