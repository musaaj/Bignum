#include "bn.h"

/**
 * bignum_add - add 2 bignum_t objects
 * @a: initialized bignum_t object
 * @b: initialized bignum_t object
 * @c: bignum_t object
 * Description: Behavior is undefined if either @a or @b
 * is not an initilized bignum_t object
 */
void bignum_add(bignum_t *a, bignum_t *b, bignum_t *c)
{
	unsigned int i;
	int carry_over = 0;
	int plus = 0;
	unsigned int len;

	if (a == NULL | b == NULL | c == NULL)
		return;
	if (a->len_of_digits > b->len_of_digits)
		len = a->len_of_digits;
	else 
		len = b->len_of_digits;
	c->len_of_digits = 0; /*set length of @c to 0*/
	for (i = 0; i < len; i++)
	{
		if (carry_over)
		{
			plus = 1;
			carry_over = 0;
		}
		plus += a->array[i] + b->array[i];
		if (plus > 9)
		{
			carry_over = 1;
			plus -= 10;
		}
		c->array[i] = plus;
		c->len_of_digits++;
		plus = 0;
	}
	if (carry_over)
	{
		c->array[i] = carry_over;
		c->len_of_digits++;
	}
}
