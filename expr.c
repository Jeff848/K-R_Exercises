/*
 ============================================================================
 Name        : DaysMonthConverter.c
 Author      : Jeffrey
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 100
#define MAXVAL 100
#define NUMBER '0'
#define LETTER 'a'

int mygetline(char *line, int max);

void push(double);
double pop(void);
double peek(void);
int getop(char *s, char *arg);
int main2(int argc, char *argv[]);

int sp = 0;
double val[MAXVAL];

int main(){
	int i;
	char *argv[] = {"expr","2412345678","300000000","4","-", "*"};
	i = main2(6,argv);
	return i;
}

int main2(int argc, char *argv[])
{

	int ans, type;
	double op2;
	char storage[MAXLINE];
	while(--argc>0){
		type = getop(storage, *(++argv));
		printf("Type %c\n", type);
		printf("Storage %s\n", storage);
		switch(type){
		case NUMBER:
			push(atof(storage));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop()-op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		default:
			printf("Error\n");
			break;
		}
	}
	ans = pop();

	return ans;
}


void push(double f)
{
	//printf("This got called for %g. SP is now %d\n", f, sp+1);
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	//printf("This returns %g. SP is now %d\n", val[sp], sp-1);
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		exit(1);
	}

}

//Prints the element at the top of the stack
double peek(void)
{
	if(sp>0) {
		//printf("Value on top of stop %g", val[sp-1]);
		return val[sp-1];
	} else {
		printf("error: stack empty\n");
		exit(1);
	}
}

int getop(char *s, char *arg)
{

	int c, d;
	//4-11 Here

	static int storage = EOF;

	c = (storage!=EOF)?storage:*arg++;
	if(c==storage)
		storage=EOF;

	while((*s = c) == ' ' || c == '\t')
		c=*arg++;
	*(s+1) = '\0';
	if(!isalnum(c) && c != '.'  && c!='-'){
		return c; /*not a number or letter or negative*/
	}
	if(c == '-' ){
		d = *arg++;
		if(isdigit(d)){
			*(++s)=c=d;
		} else {
			storage = d;
			return '-';
		}
	}

	if(isalpha(c)){ /*collect letters such as variables or math functions part */
		while(isalpha(*(++s) = c = *arg++))
			;
		if(c != EOF)
			storage = c;

		*(++s)='\0';
		return LETTER;
	}


	if(isdigit(c)||c=='-') /*collect integer part*/
		while(isdigit(*(++s) = c = *arg++))
			;
	if(c == '.') /*collect fraction part*/
		while(isdigit(*(++s) = c = *arg++))
			;
	*++s = '\0';
	if(c != EOF)
		storage = c;
	printf("%s\n",s);

	return NUMBER;
}
