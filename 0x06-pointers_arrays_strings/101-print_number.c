#include "main.h"

/**
 * print_number - prints an integer.
 * @n: input integer.
 *
 * Return: no return.
 */
void print_number(int n)
{
	unsigned int i = n, tens = 1;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	while (i = i / 10)
	{
		tens = tens * 10;
	}

	while (tens >= 1)
	{
		_putchar('0' + (n / tens));
		n = n % (tens);
		tens = tens / 10;
	}

}
