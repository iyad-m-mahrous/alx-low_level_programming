#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the number to be checked
 *
 * Return: void
 *
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		if (n > 98)
		{
			printf("%d, ", n);
			n--;
		}
		else
		{
			printf("%d, ", n);
			n++;
		}

	}
	printf("98\n");
}
