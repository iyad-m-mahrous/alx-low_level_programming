#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * @argc: Counts the number of parameters that go into main
 * @argv: Pointer of array of pointers containing strings entering main
 *
 * Description: a program that prints the number of arguments passed into it.
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	(void) argv;
	if (argc > 0)
		printf("%d\n", argc - 1);
	return (0);

}

