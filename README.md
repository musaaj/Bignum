# BIGNUM

## About BIGNUM
BIGNUM is an opensource project that plans to solve the limitation of C programming language's in not having Data Type that can handle Big number that can't be represented in binary with 64 bits or less. This project plans to solve any problems that comes with this Abstract Data Type(ADT) bignumt_t like arthemetics and comparasion operations and we are planning to add more if you have recommendation get in touch with us.

## Usage
Befor we start using BIGNUM here are 3 Things to note.
- Aignum_t can hold up to 100 digits only anything more will cause the API's to fail.<br>
- At the moment only comparison is applied but soon arthmetics will be released.<br>
- Any memory that is allocated by bn(bignum) library functions is taken care of by bn(bignum) it self. But this feature is not implemented yet.<br>

You can start using the library by inluding the main header `bn.h` in your source file and here are the API's we provide.<br>
<br>
|Function | Description|
|---------|------------|
|`string_to_bignum` | <pre><u><strong>Description</strong></u>: This function convertes a string to `bignum_t` instance.<br><u><strong>Prototype</strong></u>: `bignum_t *string_to_bignum(char *str)`<br><u><strong>Arguments</strong></u>:<br>    `@str` : is the string to convert to `bignum_t` instance which can have - or + at the beginning<br>    if no sign is provided it is implicitly converted to positive.<br><br><u><strong>Return</strong></u>:<br>   A pointer to the `bignum_t` instacne.</pre>|
|`bignum_to_string` | <pre><u><strong>Description</strong></u>: This function convertes a `bignum_t` instance to string.<br><u><strong>Prototype</strong></u>: `char *string_to_bignum(bignum_t *num)`<br><u><strong>Arguments</strong></u>:<br>    `@num` : is the `bignum_t` instance to convert to string if `@num` is negative the sign is included in the string.<br><br><u><strong>Return</strong></u>:<br>    A pointer to the string.</pre>|
|`c`| <pre><u><strong>Description</strong></u>: This function is used compare to `bignum_t` instances<br><u><strong>Prototype</strong></u>: `int c(bignum_t l, char * sign, bignum_t r)`<br><u><strong>Arguments</strong></u>:<br>    `@l`: The left hand operand `bignum_t` instance.<br>      `@sign`: The sign to compare the bignum_t instances the possible options are `>`, `<`, `==`, `>=`, `<=` and `!=`.<br>    '@r': The right hand operand `bignum_t` instance.<br><br><u><strong>Return</strong></u>:<br>    `1` (The comparison is `True`), `0` (The comparison is `False`).</pre>|
|`bn_free` | Description: This functions releases any memory that was obtained by `bn` libray functions.<br>Prototype: `void bn_free(void)`|

> Note: some things listed here are not implemented yet sorry for the inconvineince.
