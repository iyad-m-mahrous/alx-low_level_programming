#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * wcount - get the number of the words
 * @str: string
 *
 * Return: words count
 */

int wcount(char *str)
{
	int i = 0, c = 0;


	while (*(str + i) != 0)
	{
		if (*(str + i) != ' ' && (*(str + i + 1) == ' ' ||
				       *(str + i + 1) == 0))
			c++;
		i++;
	}
	return (c);
}

/**
 * wlength - get the length of the specified word number
 * @str: string
 * @wnbr: word number
 *
 * Return: word length
 */

int wlength(char *str, int wnbr)
{
	int i = 0, j = 0, wlen = 0;

	for (j = 0; j < wnbr; j++)
	{
		wlen = 0;
		while (*(str + i) == ' ')
			i++;
		while (*(str + i) != ' ' && *(str + i) != 0)
		{
			wlen++;
			i++;
		}
	}
	return (wlen);

}


/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: Double Pointer
 */

char **strtow(char *str)
{
	int i = 0, j = 0, wc;
	char **out;

	if (str == 0 || *str == 0)
		return (0);

	wc = wcount(str);

	out = (char **) malloc((sizeof(char *) * (wc + 1)));
	if (!out)
		return (0);
	for (i = 0; i < wc; i++)
	{
		out[i] = (char *) malloc(sizeof(char) * wlength(str, 1 + 1));
		if (!out[i])
		{
			for (j = 0; j < i ; j++)
				free(out[j]);
			free(out);
			return (0);
		}

	}

	out[wc] = 0;

	return (out);
}
