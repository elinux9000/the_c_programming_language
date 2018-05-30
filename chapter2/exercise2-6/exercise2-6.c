#include <stdio.h>
#include <limits.h>
int setbits(int x, int p, int n, int y)
{
/*
 * return x with n bits that begin at p set to the rightmost n bits of y
 * leaving other bits unchanged
 */
	int y_mask = ~INT_MAX;
	int x_mask = 0x01;

	x_mask <<= p;
	for (int i = 0; i < n; i++)
	{
		int y_bit = y & y_mask;

		if (y_bit)
		{
			x = x | x_mask;
		}
		else
		{
			x = x & ~x_mask;
		}
		y_mask >>= 1;
		x_mask <<= 1;
	}
	return x;
}
int main(void)
{
	int x = setbits(0, 4, 2, 0xc0000000);

	printf("x=0x%X\n", x);
	return 0;
}

