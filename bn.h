/**
 * Bignum is a simple implementation of big number
 * with precision of up to 100 digits written in C
 * The library is meant to be simple for simple uses so
 * only basic arithemetic operations are supported
 *
 * The only operations supported are; addition, subtraction
 * multiplication and division
 * Increment and decrement are also supported
 *
 * Bignum is free to use free to modify free to
 * include in commercial software free to modify
 * free to sell directly or indirecty
 */

#ifndef _FACTORS_H
#define _FACTORS_H
#include <string.h>

#define MAX_DIGITS 101
#define NULL_DIGIT 0
#define ZERO 48

typedef struct bignum
{
	int array[MAX_DIGITS];
	unsigned int digits;
} bignum_t;

bignum_t *bignum_init(bignum_t *);
bignum_t *bignum_from_string(bignum_t *, char *);
char *bignum_to_string(bignum_t *n, char *s);
void bignum_add(bignum_t *a, bignum_t *b, bignum_t *c);
#endif
