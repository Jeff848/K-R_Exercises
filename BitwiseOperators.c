/*
 ============================================================================
 Name        : BitwiseOperators.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Totes my gotes got that c lang book, bro
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int setbits(unsigned,int,int,int);
int invert(unsigned, int, int);
int rightrot(unsigned, int);
int lengthOfBit(unsigned);
int bitcount(unsigned);


int main(void) {

	//printf("209 and 40: %d\n", );

	//int xpny[4];
	int i;
	i = 7;
	//printf("i's value is %d\n", 7);
	//printf("This is what i&=(i-1) does: %d", i&=(i-1));

	//printf("%d\n", 01);
	//printf("%d", 1);
	//printf("Setbits output: %d\n", setbits(149,2,4,155));
	//printf("Invert output %d\n", invert(200,1,6));
	//printf("Rightrot output %d\n", rightrot(200,4));
	printf("Bitcount output: %d\n", bitcount(357));

	/* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

//2-6 Returns x with the n bits that begin at position p set to the rightmost n bits of y,
//leaving the other bits unchanged.
int setbits(unsigned x, int p, int n, int y){
	//Rightmost n bits of y
	//2^n -1 for int with n bits of 1
	//Then simply bitwise & to get 000...rightmost bits of y
	int i, numBits, rightBits;
	numBits=2;
	for(i=1; i<n; i++){
		numBits*=2;
	}
	rightBits=--numBits&y;
	//printf("RightBits: %d\n NumBits: %d\n",rightBits, numBits);

	//Shifting both the rightBits and the numBits to the right position
	int len;
	//Finding the length of digits (formula from wolfram alpha)
	len = lengthOfBit(x);
	rightBits<<=len-p-n;
	numBits<<=len-p-n;

	//Inverting the numBits to get 111... n 0's at p ... 111
	numBits=~numBits;

	//Using numBits to & x and isolate the non-affected bits
	x = numBits & x;

	//Setting the n bits at p of x to the rightmost bits of y by simple |
	x = rightBits | x;

	return x;
}

//2-7 Returns x with the n bits that begin at position p inverted (ie., 1 changed into 0 and vice versa),
//leaving the others unchanged.
int invert(unsigned x, int p, int n){
	//Creating "filler" number with 1s at position p for n bits and 0s everywhere else
	//2^n-1 for int with n bits of 1
	int i, numBits;
	numBits=2;
	for(i=1; i<n; i++){
		numBits*=2;
	}
	--numBits;
	//Finding the length of the digits (formula from wolfram alpha)
	int len;
	len = lengthOfBit(x);
	//Shifting numBits to the right position
	numBits<<=len-p-n;
	//The final part returns a part with only the n bits at position that are inverted
	//and another part with everything else, unchanged
	return (~x&numBits)|(x&~numBits);
}

//2-8 Returns the value of the integer x rotated to the right by n bit positions.
int rightrot(unsigned x, int n){
	//Creating "filler" number with 1s for n bits and 0s everywhere else to isolate the rotated part
	//2^n-1 for int with n bits of 1
	int i, numBits, cutOff;
	numBits=2;
	for(i=1; i<n; i++){
		numBits*=2;
	}
	--numBits;
	//Isolating the cutoff bits
	cutOff = numBits&x;
	//Finding the length of the digits (formula from wolfram alpha)
	int len;
	len = lengthOfBit(x);
	//Shifting both x to the right by the amount given and shifting cutOff to the beginning n bits
	x>>=n;
	cutOff<<=len-n;
	return cutOff|x;

	//Better version here- skips some steps that I put in because I assumed that I would need to
	//isolate the cut off part
	//return (x<<(len-n))|(x>>n);
}

int lengthOfBit(unsigned bit){
	return (int)ceil(log(bit+1)/log(2));
}

//2-9 In a two's complement system, x &= (x-1) deletes the rightmost 1-bit of x. Explain why.
//Use this observation to write a faster version of bitcount

//This deletes the rightmost 1-bit because x&= (x-1) is equivalent to x = x & (x-1)
//Therefore the left 1-bits, being the same, are copied, while the rightmost
//1-bit is turned into 0 and followed by a varying number of 1's (0 if rightmost 1-bit is rightmost bit)
//These are all different from the originial, so they all end up as 0
//The ones which were originally 0 stay 0, while the changed one also ends up as 0


/*bitcount: count 1 bits in x*/
int bitcount(unsigned x){
	int b;
	for(b = 0; x!=0; x&=x-1)
		++b;
	return b;
}
