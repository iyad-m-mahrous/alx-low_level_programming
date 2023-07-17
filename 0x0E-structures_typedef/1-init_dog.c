#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - writes the character c to stdout
 * @d: Dog
 * @name: Dog name
 * @age: dog age
 * @owner: Dog owner
 *
 * Return: Void.
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
