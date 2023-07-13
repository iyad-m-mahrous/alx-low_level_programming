#include "main.h"

/**
 * malloc_checked -  allocates memory using malloc.
 * @b: size
 *
 * Return: Pointer to allocated memory or normal process termination
 * with a status value of 98
 */

void *malloc_checked(unsigned int b)
{
	void *out;

	out = malloc(b);
	if (out)
		return (out);
	exit(98);
}
