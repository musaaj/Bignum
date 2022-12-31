#include "bn.h"

/**
 * c - compares two bignum_t instance.
 * @f: first bignum_t instance.
 * @op: This takes the sign to compare big num_t instances.
 * possible options are '>', '<' , '==', '>=', '<=', '!='
 * @s: second big num instance.
 *
 * Return: 1 (operation is True), 0 (operation is false).
 * Description: NULL is considered less than any instance of bignum_t
 * and if NULL and NULL is passed they are considerd equal.
 * If op is NULL or any invalid operator by default equal comparasion
 * is made.
 */
int c(bignum_t *f, char *op, bignum_t *s)
{
	op_comp op_comps[] = {
		{_BN_GT, &bn_gt}, {_BN_LT, &bn_lt},
		{_BN_EQ, &bn_eq}, {_BN_GE, &bn_ge},
		{_BN_LE, &bn_le}, {_BN_NE, &bn_ne}
	};
	int code, i;

	code = check_op(op);
	for (i = 0; i < _BN_OPS; i++)
	{
		if ((op_comps[i]).code == code)
			return ((op_comps[i]).comp(f, s));
	}
	return (0);
}

/**
 * check_op - cheks if the op argument for bn comp is valid or not.
 * @op: The op argument passed to bn_comp.
 *
 * Return: The corresponding macro defined for comparison in
 * bn_comparison.h. If the op does not belong to any of the valid
 * op arguments then the _BN_EQ is returned by default.
 */
int check_op(char *op)
{
	char *ops[] = {">", "<", "==", ">=", "<=", "!="};
	int m_ops[] = {_BN_GT, _BN_LT, _BN_EQ, _BN_GE, _BN_LE, _BN_NE};
	int i;

	for (i = 0; i < _BN_OPS; i++)
	{
		if (exact_match(op, ops[i]))
			return (m_ops[i]);
	}
	return (_BN_EQ);
}

/* below this and next files contain functions that does the comparasion. */

/**
 * bn_gt - performs greater than comparasion between to bignum_t
 * instances.
 * @f: The first bignum_t's address.
 * @s: The second bignum_t's address.
 *
 * Return: 1 (operation is True), 0 (operation is false).
 */
int bn_gt(bignum_t *f, bignum_t *s)
{
	int i;

	if (f == NULL)
		return (0);
	if (s == NULL)
		return (1);

	if (f->sign == 'P' && s->sign == 'N')
		return (1);
	if (f->sign == 'N' && s->sign == 'P')
		return (0);
	if (f->seek < s->seek)
		return (1);
	if (f->seek > s->seek)
		return (0);

	for (i = f->seek; i < MAX_DIGITS; i++)
	{
		if (f->array[i] > s->array[i] && f->sign == 'P')
			return (1);
		else if (f->array[i] < s->array[i] && f->sign == 'P')
			break;
		if (f->array[i] < s->array[i] && f->sign == 'N')
			return (1);
		else if (f->array[i] > s->array[i] && f->sign == 'N')
			break;
	}
	return (0);
}

/**
 * bn_lt - performs less than than comparasion between to bignum_t
 * instances.
 * @f: The first bignum_t's address.
 * @s: The second bignum_t's address.
 *
 * Return: 1 (operation is True), 0 (operation is false).
 */
int bn_lt(bignum_t *f, bignum_t *s)
{
	int i;

	if (s == NULL)
		return (0);
	if (f == NULL)
		return (1);

	if (f->sign == 'P' && s->sign == 'N')
		return (0);
	if (f->sign == 'N' && s->sign == 'P')
		return (1);
	if (f->seek < s->seek)
		return (0);
	if (f->seek > s->seek)
		return (1);
	for (i = f->seek; i < MAX_DIGITS; i++)
	{
		if (f->array[i] < s->array[i] && f->sign == 'P')
			return (1);
		else if (f->array[i] > s->array[i] && f->sign == 'P')
			break;
		if (f->array[i] > s->array[i] && f->sign == 'N')
			return (1);
		else if (f->array[i] < s->array[i] && f->sign == 'N')
			break;
	}
	return (0);
}

/**
 * bn_eq - performs is equal to comparasion between to bignum_t
 * instances.
 * @f: The first bignum_t's address.
 * @s: The second bignum_t's address.
 *
 * Return: 1 (operation is True), 0 (operation is false).
 */
int bn_eq(bignum_t *f, bignum_t *s)
{
	int i;

	if (f == NULL && s == NULL)
		return (1);
	if (f == NULL || s == NULL)
		return (0);
	if (f->sign != s->sign)
		return (0);
	if (f->seek != s->seek)
		return (0);
	for (i = f->seek; i < MAX_DIGITS; i++)
	{
		if (f->array[i] != s->array[i])
			return (0);
	}
	return (1);
}
