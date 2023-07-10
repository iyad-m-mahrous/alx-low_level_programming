#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: columns
 * @height: rows
 *
 * Return: Double Pointer
 */

int **alloc_grid(int width, int height)
{
	int i, j;
	int **new;

	if (width <= 0 || height <= 0)
		return (0);

	new = (int **) malloc(sizeof(int *) * height);
	if (!new)
		return (0);

	for (i = 0; i < height; i++)
	{
		new[i] = (int *) malloc(sizeof(int) * width);
		if (!new[i])
		{
			for (j = 0; j < i; j++)
			{
				free(new[j]);
			}
			free(new);
			return (0);
		}
		for (j = 0; j < width; j++)
			new[i][j] = 0;
	}

	return (new);
}
