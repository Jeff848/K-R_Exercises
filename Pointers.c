/*
 ============================================================================
 Name        : Pointers.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 100
#define MAX 100
int bufp = 0;
char buf[BUFSIZE];

int getch(void);
void ungetch(int);
int getint(int *pn);
int getfloat(float *pn);

int main(void) {
	float x;
	int y;
	float* pn;
	pn = &x;
	y = getfloat(pn);
	printf("returned value = %d, x = %f\n", y, x);
	return 0;
}



int getint(int *pn){
	int c, sign;

	while (isspace(c=getch()))
		;
	if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'){
		ungetch(c); //ungetch non number
		return 0;
	}
	sign = (c=='-')?-1:1;
	if(c=='+'||c=='-'){
		c = getch();
		if(!isdigit(c)){
			ungetch(c);
			return 0;
		}
	}
	for(*pn = 0; isdigit(c); c=getch())
		*pn = 10 * *pn + (c-'0');

	*pn *= sign;
	if(c!=EOF)
		ungetch(c);

	return c;
}

int getfloat(float *pn){
	int c, sign, pow;
	while (isspace(c=getch()))
		;
	if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'){
		ungetch(c); //ungetch non number
		return 0;
	}
	sign = (c=='-')?-1:1;
	if(c=='+'||c=='-'){
		c = getch();
		if(!isdigit(c)){
			ungetch(c);
			return 0;
		}
	}
	for(*pn = 0; isdigit(c); c=getch())
		*pn = 10 * *pn + (c-'0');
	if(c=='.'){
		c = getch();
		for(pow = 10;isdigit(c);c=getch()){
			*pn += (c-'0')/(float)pow;
			pow*=10;
		}
	}

	*pn *= sign;
	if(c!=EOF)
		ungetch(c);

	return c;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else if(c!=EOF)
		buf[bufp++] = c;
	else
		buf[bufp++] = '\n';
}
