#include "bn.h"

/**
 * is_eq - compares to integers and if values are not equal
 * it will print the passed message else Test passed and number
 * of the test.
 * @f: first integer.
 * @s: second integer.
 * @no: test number(index).
 * @msg: the message to print if not equal.
 *
 * Return: Void
 */
void is_eq(int f, int s, int no, char *msg)
{
	if (f == s)
	{
		printf("%d : Test passed\n", no);
		return;
	}
	printf("%d : Test failed\n", no);
	printf("%d != %d\n", f, s);
	if (msg != NULL)
		printf("%s\n", msg);
}

/**
 * is_bn_eq - compares to bignum objects and if values are not equal
 * it will print the passed message elese Test passed and the test
 * number.
 * @f: first bignum_t instances.
 * @s: second bignum_t instances.
 * @no: test number(index).
 * @msg: the message to print if not equal.
 *
 * Return: Void
 */
void is_bn_eq(bignum_t f, bignum_t s, int no, char *msg)
{
	char *sf = NULL, *ss = NULL;

	if (c(&f, "==", &s))
	{
		printf("%d : Test passed\n", no);
		return;
	}
	printf("%d : Test failed\n", no);
	sf = bignum_to_string(&f);
	ss = bignum_to_string(&s);
	printf("%s != %s\n", sf, ss);
	free(sf);
	free(ss);
	if (msg != NULL)
		printf("%s\n", msg);
}
