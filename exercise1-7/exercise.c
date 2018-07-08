#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

/*
 * Exercise 1-7
 * Print the value of EOF
 *
 * CTRL-d will generate an EOF in my terminal.
 * stty -icanon will disable buffering
 */

int main(void)
{
	int c;

	printf("\nPress <CTRL>d to generate the EOF character, f to exit.\n");
	while ((c = getchar()) != 'f')
	{
		printf("%d\n", c);

	}
	return EXIT_SUCCESS;
}

