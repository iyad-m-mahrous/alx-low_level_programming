#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument count in main
 * @av: arguments passed to main
 *
 * Return: Pointer
 */

char *argstostr(int ac, char **av)
{
	char *new;
	int size = 0, i, j, k = 0;

	if (ac == 0 || !av)
		return (0);


	for (i = 0 ; i < ac; i++)
	{
		for (j = 0; *(av[i] + j) != '\0'; j++)
		{
			size++;
		}
	}

	new = (char *) malloc(sizeof(char) * (size + ac + 1));

	for (i = 0 ; i < ac; i++)
	{
		for (j = 0; *(av[i] + j) != '\0'; j++)
		{
			new[k] = av[i][j];
			k++;
		}
		new[k] = '\n';
		k++;
	}
	new[k] = '\0';

	return (new);

}
