#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory of structure dogs
 * @d: pointer of structure
 *
 * Return: Void.
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
