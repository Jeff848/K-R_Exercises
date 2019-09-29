/*
 ============================================================================
 Name        : NumberToCharString.c
 Author      : Jeffrey
 ============================================================================
 */

/*
 * 3-4 In a two's complement number representation, our version of itoa does not handle the largest
 * negativve number, that is the value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to
 * print that value correctly, regardless of the machine on which it runs.
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAXLINE 1000

void itoa(int, char[]);
void itoaV2(int, char[], int);
void itob(int, char[], int);
double atof(char[]);
void reverse(char[]);
int getwordsize();






int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//int n;
	char characters[MAXLINE];
	itoaV2(-128,characters, 16);
	printf("-128 is %s\n", characters);
	itoaV2(256 ,characters, 4);
	printf("256 is %s\n", characters);
	printf("help\n");
	printf("123.45e-1 as a double %f", atof("123.45e-6"));
/*
	for (int i = 2; i <= 20; i++) {
		itob(255, characters, i);
		printf("decimal 255 in base %-2d : %s\n", i, characters);
	}
	*/
}



//Say that the wordsize is 4, so -(2^(wordsize-1)) is -8 or 1000 in binary.
//So n<0, thus n=-n and n = 8. In a two's complement representation, to convert signs one must
//find the one's complement (flip 1s and 0s of the binary) and add 1. For n = -8, this means
//1000->0111 (1's complement) 0111+1->1000. This clearly does not work as n does not change sign,
//so the loop runs once with ((n/=10)>0) evaluating to 0. So the resulting string has - and
//n%10+'0' once. To code around this, one must make sure that the counter

void itoa(int n, char s[]){
	int i, sign;
	//printf("help me");
	unsigned counter;
	if((sign = n)<0)
		counter= -(unsigned)n;
	else
		counter = n;
	i=0;
	do{
		s[i++]= counter%10 + '0';
	} while((counter/=10)>0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0';
	reverse(s);
}

void reverse(char s[]){

	int i, len;
	i = 0;
	while(s[i]!='\0'){
		++i;
	}
	len = i;
	if(i%2==0)
		i/=2;
	else
		i =i/2 +1;
	char temp[len];
	for(;i>0;--i){
		temp[len-i]=s[len-i];
		s[len-i]=s[i-1];
		s[i-1]=temp[len-i];
	}

}

int getwordsize() {
  int i = 1;
  int j = 1;
  while ((i <<= 1) != 0) {
    j++;
  }
  return j;
}

/*3-5 Write the function itob(n,s,b) that converts the integer b into a base b character
 * representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal
 * integer in s
 */

void itob(int n, char s[], int b){
	int i, sign;
	//printf("help me");
	unsigned counter;
	if((sign = n)<0)
		counter= -(unsigned)n;
	else
		counter = n;
	i=0;
	do{
		if(counter%b<10)
			s[i++]= counter%b + '0';
		else
			s[i++]= counter%b-10 + 'A';
	} while((counter/=b)>0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0';
	reverse(s);
}

/* 3-6
 * Write a version of itoa that accepts three arguments instead of two. The third argument is a
 * min field width; the converted number must be padded with blanks on the left if necessary to
 * make it wide enough.
 */
void itoaV2(int n, char s[], int minWidth){
	int i, sign;
	unsigned counter;
	if((sign = n)<0)
		counter= -(unsigned)n;
	else
		counter = n;
	i=0;
	do{
		s[i++]= counter%10 + '0';
	} while((counter/=10)>0);
	if(sign<0)
		s[i++]='-';
	//printf("%d until %d", i, minWidth);
	for(;i<minWidth;)
		s[i++]=' ';

	s[i]='\0';
	//printf("Unreversed result %s", s);
	reverse(s);
}

/* 4-2 Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally signed expression
 */
double atof(char s[]) {
	double val, power, expInv;
	int i, j, sign, expsign, expnum, exp;

	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-')
		++i;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10 * val + (s[i]-'0');
	if(s[i]=='.')
		++i;
	for(power = 1.0; isdigit(s[i]);i++){
		val = 10 * val + (s[i]-'0');
		power *= 10;
	}
	if(s[i]=='E'||s[i]=='e')
		++i;
	expsign = (s[i]=='-')?-1:1;
	if(s[i]=='-'||s[i]=='+')
		++i;
	for(expnum = 0;isdigit(s[i]);i++){
		expnum = 10* expnum + (s[i]-'0');
	}
	for(j=0,exp=1;j<expnum;j++,exp*=10)
		;

	expInv = (expsign==-1)?(1.0/exp):exp;

	return sign * val/power * expInv;
}
