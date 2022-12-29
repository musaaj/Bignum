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
	while (i < MAX_DIGITS)
	{
		n->array[i++] = NULL_DIGIT;
	}
	n->len_of_digits = 0;
	return (n);
}

/**
 * bignum_from_string - set a bignum_t object from a char array of digits
 * @n: pointer to a bignum_t object
 * @str: string consisting of digits
 * Return: @n after setting it
 * Description: behaviour is undefined if @n is NULL
 * or not a pointer to a bignum_t object
 * Behavior is undefined if @str is not a char array or is NULL
 */
bignum_t *bignum_from_string(bignum_t *n, char *str)
{
	unsigned int len;
	int digit;
	unsigned int i = 0;
	
	if (n == NULL | str == NULL) return (NULL);
	len = strlen(str);
	if(str[0] == '-')
	{
		n->sign = -1;
		len--;
	}
	n->len_of_digits = len;
	len--;
	while (i <= len)
	{
		digit = str[len - i] - ZERO;
		n->array[i] = digit;
		i++;
	}
	return (n);
}

/**
 * bignum_to_string - copy bignum_t object to char array
 * @n: bignum_t object
 * @s: a fixed length or malloc char array
 * Return: @s after copying @n digits to it
 * Description: Behavior is undefined if @n is not a bignum_t object or NULL
 * Behavior is undefined if @s is not a malloc char array or fixed length
 * char array or length of @s is less than digits of @n
 */
char *bignum_to_string(bignum_t *n, char *s)
{
	unsigned int i;
	unsigned int len;

	len = n->len_of_digits;
	for (i = 0; i < len; i++)
		s[i] = n->array[len - i - 1] + ZERO;
	s[len] = '\0';
	return (s);
}
