#include "main.h"
#define BASE 1000000000

/**
 * print_number - prints an integer.
 * @n: the number
 *
 * Return: void
 */

void print_number(int n)
{
	int i, number, new_base;

	new_base = BASE;

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}

	while ((n / new_base) == 0)
	{
		new_base = new_base / 10;
	}

	while (new_base >= 1)
	{
		_putchar((n / new_base) + '0');
		n = n % new_base;
		new_base = new_base / 10;
	}

}
