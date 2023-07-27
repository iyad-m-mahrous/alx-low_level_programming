#include <stdio.h>

void before_main(void)__attribute__((constructor));

/**
 * before_main - executes before main starts
 *
 * Return: Nothing
 */
void before_main(void)
{
	printf("You're beat! and yet, you must allow,
			\nI bore my house upon my back!\n");
}