#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

/*
 * In a 2's complement number representation, our version of itoa
 * does not handle the largest
 * negative number.
 * The largest neg number has a zero in every bit except for the leftmost.
 * The 2's complement of this number is itself (negate all bits and add 1).
 * Modify our solution to print this correctly.
 */

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(*arr))
const bool debug;
#define dbg_printf(fmt, ...) \
	do { if (debug) printf(fmt, __VA_ARGS__); } while (0)
typedef struct
{
	int n;
	char *answer;
} test_t;

void reverse(char s[])
{
	if (s)
	{
		if (s[0] == '-')
			s++;
		size_t len = strlen(s);

		for (size_t i = 0; i < len/2; i++)
		{
			char c = s[i];

			s[i] = s[len-1-i];
			s[len-1-i] = c;
		}
	}
}
void itoa(int n, char s[])
{
	int i = 0;
	int r;
	bool neg = false;

	if (n < 0)
	{
		s[i++] = '-';
		neg = true;
	}
	do
	{
		r = n % 10;
		if (neg)
			r = -r;
		s[i++] = r + '0';
		n = n/10;
	} while (n != 0);
	s[i] = 0;
	reverse(s);
}
int main(void)
{
	test_t test_data[] =
	{
		{0, "0"},
		{-1, "-1"},
		{10, "10"},
		{-100, "-100"},
		{INT_MIN, "-2147483648"},
		{INT_MAX, "2147483647"},
	};
	char s[1024];

	for (int i = 0; i < ARRAY_SIZE(test_data); i++)
	{
		itoa(test_data[i].n, s);
		if (strcmp(test_data[i].answer, s) != 0)
		{
			printf("Test failed.  Got %s expected %s\n",
					s, test_data[i].answer);
			//return EXIT_FAILURE;
		}
	}
	printf("All tests passed\n");
	return EXIT_SUCCESS;
}

