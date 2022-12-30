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
