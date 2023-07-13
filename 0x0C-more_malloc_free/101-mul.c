#include <stdio.h>
#include <stdlib.h>

/**
 * getlen - get length of a string
 * @str: the string
 *
 * Return: length of string
 */

int getlen(char *str)
{
	int i = 0, size = 0;

	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
		size++;
		i++;
	}
	return (size);
}



/**
 * main - multiplies inf numbers
 *
 * @argc: # of cmd line args
 * @argv: cmd line args
 * Return: 0 if success otherwisw exit(98)
 */

int main(int argc, char *argv[])
{
	int i = 0, j = 0, size1 = 0, size2 = 0;
	int digit1, digit2, product, index1, index2, sum;
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	size1 = getlen(argv[1]);
	size2 = getlen(argv[2]);
	result = malloc((size1 + size2 + 1) * sizeof(*result));
	if (!result)
		exit(98);
	for (i = 0; i < (size1 + size2); i++)
		result[i] = '0';
	result[size1 + size2] = 0;
	for (i = size1 - 1; i >= 0; i--)
	{
		for (j = size2 - 1; j >= 0; j--)
		{
			digit1 = argv[1][i] - '0';
			digit2 = argv[2][j] - '0';
			product = digit1 * digit2;
			index1 = i + j;
			index2 = i + j + 1;
			sum = product + (result[index2] - '0');
			result[index1] += sum / 10;
			result[index2] = (sum % 10) + '0';
		}
	}
	i = 0;
	while (result[i] == '0' && result[i + 1] != 0)
		i++;
	if (i > 0)
		for (j = i; j <= (size1 + size2); j++)
			result[j - i] = result[j];
	printf("%s\n", result);
	free(result);
	return (0);
}
