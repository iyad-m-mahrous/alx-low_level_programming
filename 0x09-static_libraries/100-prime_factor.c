#include <stdio.h>

/**
 * main - Entry point
 * Description: prime factors
 *
 * Return: 0
 */

int main(void)
{
	long i, result, base = 612852475143;


	for (i = 2; i <= base; i++)
	{
		while (base % i == 0)
		{
			result = i;
			base = base / i;
		}

	}

	printf("%ld\n", result);

	return (0);

}
