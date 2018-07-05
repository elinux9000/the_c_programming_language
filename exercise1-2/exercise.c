#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

/*
 * Exercise 1-2
 * Experiment to find out what happens when printf's argument string contains
 * \c, where c is not {n,t,b,",\}
 *
 * Answer: This results in compiler error: unknown escape sequence
 * Otherwise strange characters are printed.
 */

int main(void)
{
	printf("\a\n");
	printf("\e\n");
	printf("\f\n");
	return EXIT_SUCCESS;
}

