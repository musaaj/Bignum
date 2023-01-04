#include "bn.h"

/**
 * bignum_init - initializes or reset a big number object to 0
 * @n: bignum_t
 * Return: address of @n
 * Description: behaviour is undefined if @n is not a
 * pointer of bignum_t object or NULL
 */
bignum_t *bignum_init(bignum_t *n)
{
	unsigned int i = 0;

	if (!n)
		return (NULL);
	n->sign = 'P'; /* initializing default sign to positive */
	while (i < MAX_DIGITS)
	{
		n->array[i++] = NULL_DIGIT;
	}
	n->seek = MAX_DIGITS - 1; /* This sets the seek to the end of the array.*/
	return (n);
}

/**
 * string_to_bignum - initializes a bignum_t object from a char array of digits
 * @str: string consisting of digits
 *
 * Return: The address of the new bignum_t instace (Success), NULL (False).
 */
bignum_t *string_to_bignum(char *str)
{
	int len, i, j = 0;
	bignum_t *n = NULL;

	if (str == NULL || !(is_tog(str, _IS_NUMBER)))
		return (NULL);
	len = _strlen(str);
	if (len > MAX_DIGITS)
		return (NULL);
	n = malloc(sizeof(bignum_t)); /* Recording this address needed*/
	if (n == NULL)
		return (NULL);
	bignum_init(n);
	if (str[0] < 48 || str[0] > 57)
	{
		len--;
		j++;
		if (str[0] == '-')
			n->sign = 'N';
	}
	i = n->seek = MAX_DIGITS - len;
	while (i <= MAX_DIGITS)
		n->array[i++] = str[j++];

	return (n);
} /* needs some testing even though it's working */

/**
 * bignum_to_string - copy bignum_t object to char array
 * @n: bignum_t object
 *
 * Return: The bignum_t converted to string.
 * Description: Behavior is undefined if @n is not a bignum_t object or NULL
 */
char *bignum_to_string(bignum_t *n)
{
	int i, j;
	char *str = NULL;

	if (n == NULL)
		return (NULL);
	/* need to record this memory addres. */
	str = malloc(sizeof(char) * (MAX_DIGITS - n->seek + 1));
	if (str == NULL)
		return (NULL);
	for (j = 0, i = n->seek; i < MAX_DIGITS; i++, j++)
		str[j] = n->array[i];
	str[i] = '\0';
	return (str);
}
