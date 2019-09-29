/*
 ============================================================================
 Name        : VariableSizes.c
 Author      : Jeffrey
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>
//2-1 Variable Sizes

int main(void) {
	printf("This is the amount of bits in char: %d\n",CHAR_BIT);
	printf("Signed Char Range: %d <-> %d, which is -2^7 <-> 2^7-1\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned Char Max: %d, which is 2^8-1\n", UCHAR_MAX);
	printf("Short Range: %d <-> %d, which is -2^15 <-> 2^15-1\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned Short Max: %d, which is 2^16-1\n", USHRT_MAX);
	printf("Int Range: %d <-> %d, which is -2^31 <-> 2^31-1\n", INT_MIN, INT_MAX);
	printf("Unsigned Int Max: %u, which is 2^32-1\n", UINT_MAX);
	printf("Long Range: %ld <-> %ld, which is -2^63 <-> 2^63-1\n", LONG_MIN, LONG_MAX);
	printf("Unsigned Long Max: %lu, which is 2^64-1\n", ULONG_MAX);

	printf("Remember- floats are structured as: (+/-) precision multiplied by base to the e power\n");
	printf("Float Range: %.10e <-> %.10e\n", FLT_MIN, FLT_MAX);
	printf("Double Range: %.10e <-> %.10e\n", DBL_MIN, DBL_MAX);

	/*
	//2-2 Loop equivalent without using && or ||

	int true,lim,c;
	true = 1;

	for(int i = 0; true;++i){
		if(i>=lim-1)
			true=0;
		if((c==getchar)=='\n')
			true=0;
		if(c==EOF)
			true=0;
	}

	*/
	return EXIT_SUCCESS;
}
