#include "main.h"

/**
 * factorial - gets factorial of n
 * @n: integer
 *
 * Return: If n is lower than 0 return -1
 * Factorial of 0 is 1On success 1.
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
