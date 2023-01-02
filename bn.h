/**
 * Bignum is a simple implementation of big number with precision of up
 * to 100 digits written in C.
 * The library is meant to be simple for simple uses so only basic
 * arithemetic operations are supported
 * The only operations supported right now are;
 *   - basic arthmetic: addition, subtraction, multiplication, division
 *   - comparison: >, <, ==, !=, >=, <=
 *   - Increment and decrement are also supported
 *
 * Bignum is free to use free to modify free to
 * include in commercial software free to modify
 * free to sell directly or indirecty
 */

#ifndef _FACTORS_H
#define _FACTORS_H
/* main declarations and definations for Bignum */


/* macro definations */
#define MAX_DIGITS 101
#define NULL_DIGIT 0
#define ZERO 48

/* standard libary headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct bignum - struct to contain information about instance of bignum_t.
 * @array: this is where the digits are stored.
 * @seek: Where the last digit is.
 * @sign: This holds the signe of the number it takes two value 'P' and 'N'
 * 'P' for positive and 'N' for negative.
 */
typedef struct bignum
{
	char array[MAX_DIGITS];
	int seek;
	char sign;
} bignum_t;

/* local library headers */
#include "bn_string.h"
#include "bn_comparison.h"
#include "test.h"

/* function declrations */
bignum_t *bignum_init(bignum_t *);
bignum_t *string_to_bignum(char *);
char *bignum_to_string(bignum_t *n);

#endif
