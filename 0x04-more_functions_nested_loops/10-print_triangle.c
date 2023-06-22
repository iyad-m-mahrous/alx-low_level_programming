#include "main.h"

/**
 * print_triangle - draws a triangle in the terminal.
 * @size: size of thetriangle
 *
 * Return: void
 */

void print_triangle(int size)
{
	int i, j;

	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= size - i; j++)
		{
			_putchar(' ');
		}
		for (j = 1; j <= i; j++)
		{
			_putchar('#');
		}

		_putchar('\n');
	}

	if (size <= 0)
		_putchar('\n');
}
