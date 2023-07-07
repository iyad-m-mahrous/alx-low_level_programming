#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * @argc: Counts the number of parameters that go into main
 * @argv: Pointer of array of pointers containing strings entering main
 *
 * Description:   prints the minimum number of coins to -
 *  make change for an amount of money.
 * Return: 0 (Success), 1 (Error)
 */

int main(int argc, char *argv[])
{
	int total, n_coins = 0, i;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
		{
			printf("Error\n");
			return (1);
		}
	total = atoi(argv[1]);
	if (total < 0)
		{
			printf("0\n");
			return (0);
		}
	for (i = 0; i < 5 ;i++)
	{
		while ((n_coins += total / coins[i]) != 0)
		{
			total = total % coins[i];
			break;
		}
	}
	printf("%d\n", n_coins);
	return 0;
}
