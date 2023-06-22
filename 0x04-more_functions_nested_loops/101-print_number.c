#include "main.h"

/**
 * print_number - prints an integer.
 * @n: the number
 *
 * Return: void
 */

void print_number(int n)
{
	int i, number = n, new_base = 10;


	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = 0; (number / 10) > 0 ; i++)
	{
		new_base *= 10;
		number = number / 10;
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
