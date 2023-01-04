#ifndef BN_TEST_H
#define BN_TEST_H
/* bignum_t test related declarations and definations of Bignum_t */
/* this is a header for the function in test.c */
/* they help when testing things related to bignum_t objects */
/* under construction */

/* function declarations */
void is_eq(int f, int s, int no, char *msg);
void is_bn_eq(bignum_t f, bignum_t s, int no, char *msg);

#endif
