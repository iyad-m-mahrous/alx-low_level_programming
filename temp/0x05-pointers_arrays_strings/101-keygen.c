#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{

	int sum = 2772, i;

	srand(time(0));

	while (sum - ((rand() % 95) + 32) > 252)
	{
		putchar(i);
		sum -= i;
	}

	putchar(i);
	sum -= i;

	putchar(sum / 2);
	putchar(sum / 2 + sum % 2);
	putchar('\0');

	return (0);
}
