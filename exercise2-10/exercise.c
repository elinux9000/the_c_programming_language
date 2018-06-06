#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
/*
 * Rewrite lower, which converts upper case letters to lower case,
 * with a conditional expression
 */
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))
const bool debug = true;

#define dbgprintf(fmt, ...) do { if (debug) printf(fmt, __VA_ARGS__)} while 0

char lower(char c)
{
	c = (c >= 'A' && c <= 'Z') ? c-'A'+'a':c;
	return c;
}
int main(void)
{
	for (char c = 'A'; c <= 'Z'; c++)
	{
		printf("Upper %c lower %c ", c, lower(c));
		printf("lower %c lower %c\n", lower(c), lower(c));
	}
	return EXIT_SUCCESS;
}
