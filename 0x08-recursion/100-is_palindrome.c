#include "main.h"

/**
 * size - get the size of the string s
 * @s: string to evaluate
 *
 * Return: size of s
 */

int size(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + size(s + 1));
}

/**
 * check - checks if a string is a palindrome
 * @start: start of string to evaluate
 * @end: end of string to evaluate
 *
 * Return: 1 if palindrom else 0
 */

int check(char *start, char *end)
{
	if (*start == '\0')
		return (1);
	if (start == end || start > end)
		return (1);
	if (*start != *end)
		return (0);
	check(start + 1, end - 1);
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to evaluate
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int is_palindrome(char *s)
{
	return (check(s, s + size(s) - 1));
}
