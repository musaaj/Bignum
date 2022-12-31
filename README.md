# BIGNUM

## About BIGNUM
BIGNUM is an opensource project that plans to solve the limitation of C programming language's in not having Data Type that can handle Big number that can't be represented in binary with 64 bits or less. This project plans to solve any problems that comes with this Abstract Data Type(ADT) bignumt_t like arthemetics and comparasion operations and we are planning to add more if you have recommendation get in touch with us.

## Usage
- Note: bignum_t can hold up to 100 digits only anything more will cause the API's to fail.<br>
- Note: At the moment only comparison is applied we are working on it.<br>
- Note: Any memory that is allocated by bn(bignum) library functions is taken care of by bn(bignum) it self.<br>

You can start using the library by inluding the main header `bn.h` in your source file and here are the API's we provide.<br>
<br>
|Function | Description|
|---------|------------|
|string_to_bignum | Description: This function convertes a string to bignum_t instance.<br>prototype: bignum_t * string_to_bignum(char * str).<br>@str : is the string to convert to bignum_t instance which can have - or + at the beginning if no sign is provided it is implicitly converted to positive.<br>Return: a pointer to the bignum_t instacne.|
|bignum_to_string | Description: This function convertes a bignum_t instance to string.<br>prototype: char * string_to_bignum(bignum_t * num).<br>@num : is the bignum_t instance to convert to string if @num is negative the sign is included in the string.<br>Return: a pointer to the string.|
|c| Description: this function is used compare to bignum_t instances<br>prototype: int c(bignum_t l, char * sign, bignum_t r).<br>@l: The left hand operand bignum_t instace<br>@sign: The sign to compare the bignum_t instances the possible options are ">", "<", "==", ">=", "<=" and "!=".<br>Return: 1 (The comparison is True), 0 (The comparison is False).|
|bn_free| Description: This functions releases any memory that was obtained by bn libray functions.<br>prototype: void bn_free(void)|
