#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to modify
 * @old_size: current size of memory
 * @new_size: size memory will now have
 *
 * Return: Pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *out, *nptr;
	unsigned int min_size, i;

	if (ptr && !new_size)
	{
		free(ptr);
		return (0);
	}
	if (new_size == old_size)
		return (ptr);
	if (!ptr && new_size)
	{
		out = malloc(new_size);
		if (!out)
			return (0);
		return (out);
	}
	out = malloc(new_size);
	if (!out)
		return (0);

	min_size = (new_size < old_size) ? new_size : old_size;
	nptr = (char *) ptr;

	for (i = 0; i < min_size; i++)
		out[i] = nptr[i];
	free(ptr);
	return (out);
}
