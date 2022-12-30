#include "bn.h"

/**
 * bn_ne - performs not equal comparasion between to bignum_t
 * instances.
 * @f: The first bignum_t's address.
 * @s: The second bignum_t's address.
 *
 * Return: 1 if the operation is True, 0 if the opration is false.
 */
int bn_ne(bignum_t *f, bignum_t *s)
{
	int i;

	if (f == NULL && s == NULL)
		return (0);
	if (f == NULL || s == NULL)
		return (1);
	if (f->sign != s->sign)
		return (1);
	if (f->seek != s->seek)
		return (1);
	for (i = f->seek; i < MAX_DIGITS; i++)
	{
		if (f->array[i] != s->array[i])
			return (1);
	}
	return (0);
}

/**
 * bn_ge - performs greater or equal comparasion between to bignum_t
 * instances.
 * @f: The first bignum_t's address.
 * @s: The second bignum_t's address.
 *
 * Return: 1 if the operation is True, 0 if the opration is false.
 */
int bn_ge(bignum_t *f, bignum_t *s)
{
	if (bn_eq(f, s) || bn_gt(f, s))
		return (1);
	return (0);
}

/**
 * bn_le - performs less than or equal comparasion between to bignum_t
 * instances.
 * @f: The first bignum_t's address.
 * @s: The second bignum_t's address.
 *
 * Return: 1 if the operation is True, 0 if the opration is false.
 */
int bn_le(bignum_t *f, bignum_t *s)
{
	if (bn_eq(f, s) || bn_lt(f, s))
		return (1);
	return (0);
}

