#include "variadic_functions.h"
#include <stdio.h>


/**
 * print_char - prints variadic argument char
 * @args: variadic list
 *
 * Return: Nothing
 */

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints variadic argument int
 * @args: variadic list
 *
 * Return: Nothing
 */

void print_int(va_list args)
{
	printf("%i", va_arg(args, int));
}

/**
 * print_float - prints variadic argument float
 * @args: variadic list
 *
 * Return: Nothing
 */

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_str - prints variadic argument string
 * @args: variadic list
 *
 * Return: Nothing
 */

void print_str(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (!str)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * @...: Arguments Variadic
 *
 * Return: Nothing
 */

void print_all(const char * const format, ...)
{
	ctf ctf_list[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_str}
	};

	int i = 0, j = 0;
	va_list args;
	char *comma = "";

	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == ctf_list[j].c)
			{
				printf("%s", comma);
				ctf_list[j].f(args);
				comma = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
