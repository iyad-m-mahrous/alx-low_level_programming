#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * @argc: Counts the number of parameters that go into main
 * @argv: Pointer of array of pointers containing strings entering main
 *
 * Description:  a program that adds two numbers.
 * Return: 0 (Success), 1 (Error)
 */

int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	if (argc <= 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; i++)
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				continue;
			}
			else if ( argv[i][j] != '-')
			{
				printf("Error\n");
				return (1);
			}
		}
	}

	for (i = 1; i < argc; i++)
	{
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}

