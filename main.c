#include "bn.h"

/**
 * main - test the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	bignum_t *n;
	bignum_t *m;

	n = string_to_bignum("7849377843");
	m = string_to_bignum("78493778433");

    /* test for bn_eq */
	is_bn_eq(*n, *m, 0, "This is a bn_eq's test");

	is_eq(c(n, "==", m), 0, 1, "Equal");
	is_eq(c(n, "!=", m), 1, 2, "Not Equal");
	is_eq(c(n, ">=", m), 0, 3, "Greater than or Equal");
	is_eq(c(n, "<=", m), 1, 4, "Less than or Equal");
	is_eq(c(n, ">", m), 0, 5, "Greater than");
	is_eq(c(n, "<", m), 1, 6, "Less than");

	/* add tests if you have some */
	/* i did not have enogh time to test it */
	return (0);
}


