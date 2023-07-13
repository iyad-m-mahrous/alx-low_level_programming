#include "main.h"

/**
 * _calloc -  allocates memory using malloc and initializes in 0
 * @nmemb: number of elements of array to allocate
 * @size: size of elements
 *
 * Return: Pointer to allocated memory or normal process termination
 * with a status value of 98
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *out;
	unsigned int i;
	char *temp;

	if (!nmemb || !size)
		return (0);
	out = malloc(nmemb * size);
	if (!out)
		return (0);
	temp = (char *) out;

	for (i = 0; i < (nmemb * size); i++)
		temp[i] = 0;
	return (out);

}
