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
 */

int main(void)
{
	int c;

	while ((c = getchar()) != 'f')
		printf("Value of getchar() != EOF is %d\n", getchar() != EOF);
	return EXIT_SUCCESS;
}

