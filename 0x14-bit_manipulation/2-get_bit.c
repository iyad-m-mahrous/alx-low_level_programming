#include "main.h"

/**
 * get_bit - gets the value of a bit at index,
 * starting from least bit at 0
 *
 * @n: number to get bit from
 * @index: index of bit
 *
 * Return: value of bit, or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1ul;

	if (index > 63)
		return (-1);
	mask = mask << index;
	return ((mask & n) ? (1) : (0));
}
