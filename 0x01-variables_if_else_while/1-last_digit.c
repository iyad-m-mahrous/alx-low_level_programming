#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry Function
 *
 * Description: Task 1
 *
 * Return: 0 (Success)
 */

int main(void)
{
	int n, d;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	d = n % 10;
	/* your code goes there */
	if (d > 5)
		printf("Last digit of %d is %d and is greater than 5\n", n, d);
	else if (d == 0)
		printf("Last digit of %d is 0 and is 0\n", n);
	else
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, d);

	return (0);
}
