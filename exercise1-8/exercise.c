#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>
#include <termios.h>
#include <unistd.h>


/*
 * Exercise 1-8
 * Write a program to count blanks, tabs, and newlines
 */
#define dbg_printf(...) do { if (debug) printf(__VA_ARGS__); } while (0)

/* the terminal in non canonical mode sends 4 when ctrl-d
 * is pressed
 */
#define EOT 4
const bool debug;

int main(void)
{
	int c;
	unsigned int blanks = 0;
	unsigned int tabs = 0;
	unsigned int newlines = 0;

	printf("\nThis program counts blanks, tabs, and newlines\n");
	while ((c = getchar()) != EOT && c != EOF)
	{
		dbg_printf("c=%d\n", c);
		switch (c)
		{
			case ' ':
				blanks++;
				break;
			case '\t':
				tabs++;
				break;
			case '\n':
				newlines++;
				break;
			default:
				break;
		}
	}
	printf("\nblanks:%u\ntabs:%u\nnewlines:%u\n", blanks, tabs, newlines);
	return EXIT_SUCCESS;
}

