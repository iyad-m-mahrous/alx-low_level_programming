#include "main.h"
/**
 * _strcat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 *
 * Return: the pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	char *main_dest = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*(dest) = '\0';
	return (main_dest);
}
