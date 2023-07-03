#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints diagonal sums of square matrix
 *
 * @a: square matrix of integers
 * @size: col & row size of matrix
 *
 * Return: always void
 */
void print_diagsums(int *a, int size)
{
	int diag1 = 0, diag2 = 0, i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
				diag1 += a[i * size + j];
			if (i + j + 1 == size)
				diag2 += a[i * size + j];
		}
	}

	printf("%d, %d\n", diag1, diag2);
}
