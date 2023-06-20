#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to be checked
 *
 * Return:  the last digit of a number
 *
 */
int print_last_digit(int n)
{
	_putchar(_abs((n + 10) % 10) + '0');
	return (_abs((n + 10) % 10));
}

/**
 * _abs - prints the absolute value of a number
 * @n: the number to be checked
 *
 * Return: absolute value of n
 *
 */
int _abs(int n)
{
	if (n >= 0)
	{
		return (n);
	}
	else
	{
		return (n * -1);
	}
}
