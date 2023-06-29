#include "main.h"

/**
 * print_number - prints an integer.
 * @n: input integer.
 *
 * Return: no return.
 */
void print_number(int n)
{
	unsigned int i = n;

	if (n < 0)
	{
		_putchar('-');
		i = -i;
	}

	_putchar((i % 10) + '0');
	if ((i / 10) > 0)
		print_number(i / 10);

}
