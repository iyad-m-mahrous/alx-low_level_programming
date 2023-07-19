#include "3-calc.h"

/**
 * main - program that performs simple operations
 *
 * @argc: Counts the number of parameters that go into main
 * @argv: Pointer of array of pointers containing strings entering main
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	int result, (*f)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if ((argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*'
	     && argv[2][0] != '/' && argv[2][0] != '%') || strlen(argv[2]) != 1)
	{
		printf("Error\n");
		exit(99);
	}

	if ((argv[2][0] == '/' || argv[2][0] == '%') && (atoi(argv[3]) == 0))
	{
		printf("Error\n");
		exit(100);
	}

	f = get_op_func(argv[2]);
	result = f(atoi(argv[1]), atoi(argv[3]));
	printf("%i\n", result);

	return (0);
}
