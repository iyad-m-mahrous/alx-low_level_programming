#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created by
 * alloc_grid function.
 * @grid: matrix double pointer
 * @height: rows (pointer)
 *
 * Return: Nothing
 */

void free_grid(int **grid, int height)
{
	int i;

	if (!grid || height <= 0)
		return;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
