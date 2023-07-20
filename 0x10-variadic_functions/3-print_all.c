#include "variadic_functions.h"
#include <stdio.h>


/**
 * print_char - prints variadic argument char
 * @list: variadic list
 *
 * Return: Nothing
 */

void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * print_int - prints variadic argument int
 * @list: variadic list
 *
 * Return: Nothing
 */

void print_int(va_list list)
{
	printf("%i", va_arg(list, int));
}

/**
 * print_float - prints variadic argument float
 * @list: variadic list
 *
 * Return: Nothing
 */

void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * print_str - prints variadic argument string
 * @list: variadic list
 *
 * Return: Nothing
 */

void print_str(va_list list)
{
	char *str;

	str = va_arg(list, char *);
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
