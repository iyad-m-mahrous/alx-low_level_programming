#include "main.h"

/**
 * flip_bits - return number of bits that would need to be flipped to
 * transform one number to another
 *
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip to convert numbers
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m, mask = 1ul;
	unsigned int num_diff = 0;

	while (mask)
	{
		if (diff & mask)
			num_diff++;
		mask = mask << 1;
	}
	return (num_diff);
}
