#include "main.h"

/**
 * sqrt_test - checks if n = b x b
 * @n: the number to check the sqrt of
 * @b: the potential sqrt
 *
 * Return: -1 if no sqrt else the sqrt
 */

int sqrt_test(int n, int b)
{
	if (n < b * b)
		return (-1);
	if (n == b * b)
		return (b);
	if (n > b * b)
		return (sqrt_test(n, b + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: number to get sqrt of
 *
 * Return: returns the natural square root of a number.
 * If n does not have a natural square root, the function should return -1.
 */
int _sqrt_recursion(int n)
{
	return (sqrt_test(n, 1));
}
