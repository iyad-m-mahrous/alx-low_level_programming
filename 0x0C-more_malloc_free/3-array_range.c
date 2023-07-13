#include "main.h"

/**
 * array_range -  creates an array of integers
 * The array created should contain all the values
 * from min (included) to max (included), ordered from min to max
 * @min: minimal value
 * @max: maximum value
 *
 * Return: Pointer to allocated memory of s1 + nbytes of s2
 */

int *array_range(int min, int max)
{
	int *out, i;

	if (min > max)
		return (0);
	out = malloc((max - min + 1) * sizeof(*out));
	if (!out)
		return (0);
	for (i = 0; i < (max - min + 1); i++)
		out[i] = min + i;
	return (out);
}
