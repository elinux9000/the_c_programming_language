#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

/*
 * Exercise 1-6
 * Verify that the expression getchar() != EOF is 0 or 1
 *
 * CTRL-d will generate an EOF in my terminal.
 * stty -icanon will disable buffering
 */

int main(void)
{
	int c;

	printf("This program prints the integer value of the entered ");
	printf("character.\nEnter f to finish, CTRL-d to generate an EOF ");
	printf("char.\nstty -icanon before running the program will disable ");
	printf("buffering\n");
	while ((c = getchar()) != 'f')
	{
		printf("Value of char is %d\n", c);
		printf("Value of getchar() != EOF is %d\n", c != EOF);

	}
	return EXIT_SUCCESS;
}

