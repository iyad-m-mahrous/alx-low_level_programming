#include "main.h"

/**
 * print_binary - print an unsigned int in binary
 *
 * @n:
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1ul;
	char digit = '0';

	mask = mask << 63;
	while (digit == '0' && mask)
	{
		digit = (n & mask) ? '1' : '0';
		mask = mask >> 1;
	}

	while (mask)
	{
		_putchar(digit);
		digit = (n & mask) ? '1' : '0';
		mask = mask >> 1;
	}
	_putchar(digit);
}
