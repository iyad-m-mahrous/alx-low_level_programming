#include "main.h"

/**
 * _islower - checks for lowercase character
 * @c: the character to be checked
 *
 * Return: 1 if c is lowercase otherwise 0
 *
 */
int _islower(int c)
{
	return ((c >= (int)'a' && c <= (int)'z') ? 1 : 0);

}
