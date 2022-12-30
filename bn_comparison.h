#ifndef BN_COMPARISON_H
#define BN_COMPARISON_H

/* codes used  for comparison */
#define _BN_OPS 6 /* number of operations */
#define _BN_GT 1 /* Greater than */
#define _BN_LT 2 /* Less than */
#define _BN_EQ 3 /* is Equal to */
#define _BN_GE 4 /* Greater than or Equal to */
#define _BN_LE 5 /* Less than or Equal to */
#define _BN_NE 6 /* Not Equal */

/**
 * struct op_comp - contains comparation operators function mapper.
 * @code: The code that is used to access the comparison function.
 * @comp: The funciton used to compare.
 *
 * Description: struct used to map function for bignum_t instances
 * comparison.
 */
typedef struct op_comp
{
	int code;
	int (*comp)(bignum_t *, bignum_t *);
} op_comp;


/* function declarations */
int c(bignum_t *f, char *op, bignum_t *s);
int check_op(char *);

/* op_comp functions that compares two bignum_t instances*/
int bn_gt(bignum_t *f, bignum_t *s);
int bn_lt(bignum_t *f, bignum_t *s);
int bn_eq(bignum_t *f, bignum_t *s);
int bn_ge(bignum_t *f, bignum_t *s);
int bn_le(bignum_t *f, bignum_t *s);
int bn_ne(bignum_t *f, bignum_t *s);

#endif
