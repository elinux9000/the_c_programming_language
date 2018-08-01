#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>
#include <termios.h>
#include <unistd.h>


#define dbg_printf(...)	{ do { if (debug) printf(__VA_ARGS__); } while (0); }

/*
 * Exercise 1-13
 * Write a program that prints a vertical histogram of the lengths of words in
 * its input.
 */


/* the terminal in non canonical mode sends 4 when ctrl-d
 * is pressed
 * stty -icanon -echo
 */
#define EOT 4

const bool debug;

int main(void)
{
	int c;
	int len = 0;
	int max = 0;
	int h[1024] = {0};

	printf("This program will print a histogram of the length of words\n");
	while ((c = getchar()) != EOF && c != EOT)
	{
		dbg_printf(" c=%d\n", c);
		if (c == '\t' || c == ' ' || c == '\n')
		{
			h[len]++;
			if (max < len)
				max = len;
			len = 0;
		}
		else
		{
			len++;
		}
		putchar(c);
	}
	for (int i = 0; i < max; i++)
	{
		printf("len %d = %d\n", i, h[i]);
	}

	return EXIT_SUCCESS;
}

