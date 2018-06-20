#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/*
 * Write a function expand (s1, s2) that expands shorthand nota-
 * tions like a - z in the string s1 into the equivalent complete list
 * abc ... xyz in s2. Allow for letters of either case and digits, and be
 * prepared to handle cases like a-b-c and a-zO-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(*arr))
const bool debug = false;
#define dbg_printf(fmt, ...) do { if (debug) printf(fmt,__VA_ARGS__);} while(0)
typedef struct
{
	char *s;
	char *answer;
} test_t;
typedef enum
{
	INIT, A0, HYPHEN, M0, N0, M1, HYPHEN_NUM

} state_t;

char *state_name[] = {"INIT","A0","HYPHEN","M0","N0","M1","HYPHEN_NUM"};

void cexpand(char start, char end, char *s, size_t *j)
{
	for (char c=start; c<=end; c++)
	{
		s[*j]=c;
		(*j)++;
	}
}
void nexpand(int start, int end, char *s, size_t *j)
{
	char m[100];
	for (int c=start; c<=end; c++)
	{
		sprintf(m, "%d", c);
		sprintf(&s[*j], "%s",m);
		(*j) += strlen(m);
	}
}
void expand(char *s1, char *s2)
{
	state_t state = INIT;

	memset(s2, 0, 1024);
	size_t len = strlen(s1);
	size_t j = 0;
	char a0;
	bool m0, m1;
	char n0;

	dbg_printf("Expanding %s\n",s1);

	for (size_t i=0; i < len; i++)
	{
		char c = s1[i];
		s2[j++]=c;
		dbg_printf("state=%s c=%c \n",state_name[state],c);
		switch (state)
		{
			case INIT:
				m0 = m1 = false;
				if (isalpha(c))
				{
					a0 = c;
					state = A0;
				}
				else if (isdigit(c))
				{
					n0 = c;
					state = N0;
				}
				else if (c == '-')
				{
					m0 = true;
					state = M0;
				}
				break;
			case A0:
				if (c == '-')
				{
					state = HYPHEN;
					m0 = true;
				}
				else
				{
					if (isdigit(c))
					{
						n0 = c;
						state = N0;
					}
					else 
					{
						state = INIT;
					}
				}
				break;
			case HYPHEN:
				if (isdigit(c))
				{
					n0 = c;
					state = N0;
				}
				else
				{
					if (islower(a0))
					{
						if (islower(c) 
							&& c > a0 
							&& c <='z')
						{
							j -= 3;
							cexpand(a0,c,s2,&j);
						}
						state = INIT;
					}
					else //a0 is upper
					{
						if (isupper(c) 
							&& c > a0
							&& c <= 'Z')
						{
							j -= 2;
							cexpand(a0,c,s2,&j);

						}
						state = INIT;
					}
				}
				break;
			case M0:
			if (isdigit(c))
			{
				n0 = c;
				state = N0;
			}
			else if (isalpha(c))
			{
				a0 = c;
				state = A0;
			}
			else
			{
				state = INIT;
			}
			break;
			case N0:
			if (c == '-')
			{
				state = HYPHEN_NUM;
			}
			else
			{
				state = INIT;
			}
			break;
			case HYPHEN_NUM:
			if (c == '-')
			{
				m1 = true;
				state = M1;
			}
			else if (isdigit(c) )
			{
				int num0  = n0 - '0';
				if (m0)
					num0 = -num0;
				int num1 = c - '0';
				if (num1 > num0)
				{
					j -= 3;
					if (m0)
						j--;
					nexpand(num0,num1,s2,&j);
				}
				state = INIT;
			}
			break;
			case M1:
			if (isdigit(c) )
			{
				int num0 = n0 - '0';
				if (m0)
					num0 = -num0;
				int num1 = c - '0';
				num1 = -num1;
				dbg_printf("num0=%d num1=%d\n",num0,num1);
				if (num1 > num0)
				{
					j -= 5;
					nexpand(num0,num1,s2,&j);
				}
				state = INIT;
			}

		}
			
	}
}

int main(void)
{
	char *test_data[] = {
		"a-d0-5", "abcd012345",
		"-a-d-a", "-abcd-a",
		"-a-D-c-e-", "-a-D-cde-",
		"a--d", "a--d",
		"8-0", "8-0",
		"-8--6", "-8-7-6",
		"-2-1", "-2-101",
		"---a-c", "---abc",
		"---2-0-a-c", "---2-10-abc",
		"A-c", "A-c",
		"a-C", "a-C",
		"a-a", "a-a",
		"a-z", "abcdefghijklmnopqrstuvwxyz",
		"a-9", "a-9",
		"-9-a", "-9-a",
		"9-a", "9-a",
		"-2--1", "-2-1",
		"a-1-2", "a-1012"
	};
	char s2[1024];

	for (int i = 0; i < ARRAY_SIZE(test_data); i += 2)
	{
		expand(test_data[i], s2);
		if (strcmp(test_data[i+1], s2) != 0)
		{
			printf("Test failed.  Expanded %s expected %s "
			"got %s\n", test_data[i], test_data[i+1], s2);
			return EXIT_FAILURE;
		}
		else
		{
			printf("Test passed.  Expanded %s got %s\n", test_data[i], s2);
		}
	}
	return EXIT_SUCCESS;
}

