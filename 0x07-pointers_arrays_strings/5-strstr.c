#include "main.h"

/**
 * _strstr - locates a substring
 *
 * @haystack: string to search
 * @needle: substring to find
 *
 * Return: pointer to start of needle
 * in haystack
 */
char *_strstr(char *haystack, char *needle)
{
	char *main_needle = needle, *similar;

	while (*needle != '\0')
	{
		while (*haystack != '\0' && *haystack != *needle)
		{
			haystack++;
		}
		if (*haystack == '\0')
			return (0);

		similar = haystack;

		while (*haystack == *needle && *needle != '\0' && *haystack != '\0')
		{
			haystack++;
			needle++;
		}

		if (*needle == '\0')
		{
			return (similar);
		}
		else if (*haystack == '\0')
		{
			return (0);
		}


		needle = main_needle;
	}
	return (0);
}
