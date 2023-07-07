#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * @argc: Counts the number of parameters that go into main
 * @argv: Pointer of array of pointers containing strings entering main
 *
 * Description: a program that prints its name, followed by a new line.
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);

}
