#include "main.h"

/**
 * _isalpha - checks for alpabet character
 * @c: the character to be checked
 *
 * Return: 1 if c is a letter otherwise 0
 *
 */
int _isalpha(int c)
{
	return (((c >= (int)'a' && c <= (int)'z') ||
				(c >= (int)'A' && c <= (int)'Z')) ? 1 : 0);

}
