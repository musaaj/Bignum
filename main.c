#include "bn.h"

/**
 * main - test the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	bignum_t n;
	bignum_t m;

	bignum_from_string(&n, "7849377843");
	bignum_from_string(&m, "78493778433");

	is_eq(c(&n, "==", &m), 0, 1, "Equal");
	is_eq(c(&n, "!=", &m), 1, 2, "Not Equal");
	is_eq(c(&n, ">=", &m), 0, 3, "Greater than or Equal");
	is_eq(c(&n, "<=", &m), 1, 4, "Less than or Equal");
	is_eq(c(&n, ">", &m), 0, 5, "Greater than");
	is_eq(c(&n, "<", &m), 1, 6, "Less than");

	/* add tests if you have some */
	/* i did not have enogh time to test it */
	return (0);
}


