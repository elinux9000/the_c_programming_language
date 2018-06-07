#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define dbg_printf(fmt, ...)\
do { if (debug) printf(fmt, __VA_ARGS__); } while (0)
const bool debug = true;

/*
 * Write a function escape(s,t) that converts chars like newline and tab into
 * visible escape sequences like \n and \t as it copies t to s.  Use a switch.
 * Write a function for the other direction as well
 */
void escape(char *s, char *t)
{
	size_t len = strlen(t);
	size_t j = 0;

	for (size_t i = 0; i < len; i++)
	{
		switch (t[i])
		{
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] =  t[i];
				break;
		}
	}
}
void unescape(char *s, char *t)
{
	size_t len = strlen(t);
	size_t j = 0;
	int i;

	for (i = 0; i < len-1; i++)
	{
		switch (t[i])
		{
			case '\\':
				i++;
				switch (t[i])
				{	case 't':
						s[j++] = '\t';
						break;
					case 'n':
						s[j++] = '\n';
						break;
					default:
						i--;
						s[j++] = t[i];
						break;
				}
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	for (; i < len; i++)
		s[j++] = t[i];
}
int main(void)
{
	char *s = calloc(1024, sizeof(char));
	char *t = calloc(1024, sizeof(char));

	if (s && t)
	{
		escape(s, "a	b	c\n");
		printf("%s\n", s);
		unescape(t, s);
		printf("%s\n", t);

		memset(t, 0, 1024);
		unescape(t, "\\a\t\\\nb");
		printf("%s\n", t);
	}
	return EXIT_SUCCESS;
}

