/*
 * To understand why x &= (x-1) deletes the rightmost bit in x
 * consider the rightmost bit of x.
 * It can be 0 or 1.  If it is 1 then it will be set to zero when
 * anded with x-1.
 * If it is 0, then the rightmost bit of (x-1) will be 1
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))
#define dbgprintf(fmt, ...) printf(fmt, __VA_ARGS__)
const bool debug = true;

void dec2bin(int x, char *buf)
{
	unsigned int mask = INT_MAX;

	mask++;
	sprintf(buf, "0");
	while (!(mask & x) && mask)
	{
		mask >>= 1;
	}
	while (mask)
	{
		if (mask & x)
			sprintf(buf++, "1");
		else
			sprintf(buf++, "0");
		mask >>= 1;
	}
}

int bitcount(int x)
{
	int num = 0;

	while (x)
	{
		num++;
		x = x & (x-1);
	}
	return num;
}

int main(void)
{
	//Gain a feeling for what happens when anding
	//a variable with 1 less than itself
	char buf[1024];

	for (int i = 0; i < 16; i++)
	{
		int x = i;

		while (x > 0)
		{
			dec2bin(x, buf);
			printf("%s & ", buf);
			dec2bin(x-1, buf);
			printf("%s = ", buf);
			dec2bin(x&(x-1), buf);
			printf("%s\n", buf);
			x &= (x-1);
		}
		printf("\n");

	}

	for (int i = 0; i < 16; i++)
		printf("%d has %d bits\n", i, bitcount(i));
	return EXIT_SUCCESS;
}
