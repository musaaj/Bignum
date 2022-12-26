#include "bn.h"
#include <stdio.h>

/**
 * main - example of bignum_t operations
 */
void main(void)
{
	/* declare objects */
	bignum_t a, b, c;
	char *s = "999";
	char *s2 = "1034";
	char str[MAX_DIGITS];

	/* initialise the objects */
	bignum_init(&a);
	bignum_init(&b);
	bignum_init(&c);
	/* assign values from string */
	bignum_from_string(&a, s);
	bignum_from_string(&b, s2);
	/* add values of @a and @b and store the result in @c */
	bignum_add(&a, &b, &c);
	/* copy digits of @c to @str */
	bignum_to_string(&c, str);
	/* print the @str to stdout */
	printf("%s + %s = %s\n", s, s2, str);
	return;
}
