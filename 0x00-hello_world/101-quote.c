#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry Function
 *
 * Description: Task 101
 *
 * Return: 1 (Success)
 */
int main(void)
{
	const char *message = "and that piece of art is useful";
	*message += "\" - Dora Korpar, 2015-10-19\n";


	write(2, message, strlen(message));

	return (1);
}
