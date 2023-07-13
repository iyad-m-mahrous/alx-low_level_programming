#include "main.h"

/**
 * string_nconcat -  concatenates two strings
 * @s1: string1
 * @s2: string2
 * @n: n bytes of string 2
 *
 * Return: Pointer to allocated memory of s1 + nbytes of s2
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *out;
	char *emp = "";
	unsigned int s1_size = 0, s2_size = 0, i = 0;

	if (!s1)
		s1 = emp;
	if (!s2)
		s2 = emp;
	while (s1[i] != 0)
	{
		i++;
	}
	s1_size = i;
	i = 0;
	while (s2[i] != 0)
	{
		i++;
	}
	s2_size = i;
	if (n > s2_size)
		n = s2_size;
	out = malloc((s1_size + n + 1) * sizeof(*out));
	if (!out)
		return (0);
	for (i = 0; i < s1_size ; i++)
	{
		out[i] = s1[i];
	}
	for (i = 0; i < n; i++)
	{
		out[i + s1_size] = s2[i];
	}
	out[s1_size + n] = 0;

	return (out);

}
