#include "main.h"
#include <stdio.h>
/**
 * infinite_add - adds two numbers
 * @n1: number one.
 * @n2: number two.
 * @r: buffer that the function will use to store the result.
 * @size_r: buffer size:
 * Return: the pointer to dest.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int size1 = 0, size2 = 0, r_size = 0;
	char result[200];
	char *num1 = n1;
	char *num2 = n2;
	int i, temp;

	while (*num1 != '\0')
	{
		num1++;
		size1++;
	}
	while (*num2 != '\0')
	{
		num2++;
		size2++;
	}
	if (size1 >= size_r || size2 >= size_r)
		return (0);
	for (i = 0; i < 200; i++)
		result[i] = 100;
	for (i = 0; i < size1; i++)
		result[i] = (n1[size1 - 1 - i] - '0');
	for (i = 0; i < size2; i++)
		result[i] += (n2[size2 - 1 - i] - '0');
	for (i = 0; result[i] < 100; i++)
	{
		result[i + 1] += result[i] / 10;
		result[i] %= 10;
	}
	i = 0;
	while (result[i] < 100)
	{
		r_size++;
		i++;
	}
	if (result[r_size] > 100)
		r_size++;
	if (r_size >= size_r)
		return (0);
	for (i = 0; i < r_size; i++)
	{
		if (result[r_size - i - 1] > 100)
			result[r_size - i - 1] = result[r_size - i - 1] - 100;
		r[i] = result[r_size - i - 1] + '0';
	}
	r[r_size] = '\0';
	return (r);
}
