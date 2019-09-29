/*
 ============================================================================
 Name        : PolishCalculator.c
 Author      : Jeffrey
 ============================================================================
 */

/*
 * 4-3
 * Given the basic framework, it's straightforward to extend the calculator. Add the modulus operator (%)
 * and provisions for negative numbers
 */

/*
 * 4-4
 * Add commands to print the top stack of the stack without popping, to duplicate it, and to swap
 * the top two elements. Add a command to clear the stack.
 *
 * Test code: //Put after case '\n'
 *
	printf("At top of stack: %g\n", peek());
	printf("Let's duplicate that!\n");
	duplicate();
	op2 = pop();
	printf("Let's pop() two times to see: %g, %g\n", op2, pop());
	printf("Now let's push 4.0 then %g and swap them!\n", op2);
	push(4.0);
	push(op2);
	swap();
	printf("This is the result: %g\n", pop());
	printf("Now, let's add a bunch of stuff to stack\n");
	for(int i = 0; i< 10; ++i)
		push(1.0);
	printf("And clear it.");
	clear();
	pop(); //Should print error
 */

/*
 * 4-5
 * Add access to library functions like sin, exp,and pow. See  <math.h>.
 */

/*
 * 4-6
 * Add commands for handling variables (It's easy to provide 26 variables with single letter names)
 * Add a variable for the most recently printed value
 */

/*
 * 4-7
 * Write a routine unget(s) that will push back an entire string onto the input. Should ungets know about
 * buf and bufp, or should it just use ungetch?
 */

/*
 * 4-8
 * Suppose that there will never be more than one character of pushback. Modify getch and ungetch
 * accordingly
 */

/*
 * 4-9
 * Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought
 * to be if an EOF is pushed back, then implement your design.
 */
/*
 * A pushed back EOF should be equivalent to a \n case. Therefore, when using ungetch(EOF), one should have
 * a check for EOF, and store \n instead.
 */


/*
 * 4-10
 * An alternate organization uses getline to read an entire input line; this makes getch and ungetch
 * unnecessary. Revise the calculator to use this approach.
 */

/*
 * 4-11
 * Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define LETTER 'a'
#define MAXVAL 100
#define BUFSIZE 100
#define MAXLINE

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

//4-7 Here
void ungets(char[]);

//4-4 Here
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);

//4-10 Here
int readLine(char[], int);

int bufp = 0;
char buf[BUFSIZE];
int sp = 0;
double val[MAXVAL];

//4-6 Here
double varStorage[26];
int hasStorage[26];



int main()
{
	int type, holder;
	double op2;
	char s[MAXOP];
	double Ans;

	/*
	// Test code for 4-7
		char s[] = "Here is my string\n";
		int c;
		ungets(s);
		while((c = getch()) != EOF)
			putchar(c);
		return 0;
	 */


	while((type = getop(s)) != EOF)
	{
		//printf(" %s then", s);
		switch(type)
		{

			case NUMBER:
				push(atof(s));
				break;
			case LETTER:
				//4-5 Here
				if(strcmp(s,"sin")==0)
					push(sin(pop()));
				else if (strcmp(s, "exp")==0)
					push(exp(pop()));
				else if (strcmp(s, "pow")==0){
					op2 = pop();
					push(pow(pop(),op2));
				} else if (strcmp(s, "clear")==0){
					//clear();
					printf("Stack has been cleared\n");
				} else if (strcmp(s, "Ans")==0){
					push(Ans);
				} else if (isalpha(s[0])){
					//4-6 Here too
					holder = tolower(s[0])-'a';
					if(!hasStorage[holder]){
						duplicate();
						varStorage[holder]=pop();
						hasStorage[holder] = 1;

						//printf("Peek at var Storage %g", peek());
					}else{
						push(varStorage[holder]);
					}
					//printf("varStorage: %g", varStorage[holder]);
				} else {
					//Var storage for multi-char variables?
					printf("%s", s);
				}
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
			case '%':
				op2 = pop();
				if(op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				Ans = pop();
				printf("\t%.8g\n", Ans);
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
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

//Swaps the top element with the second to top one
void swap(void)
{
	double s;
	if(sp>1){
		s = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = s;
	} else {
		printf("error: not enough elements on stack\n");
	}
}

//Clears the whole stack
void clear(void){
	sp = 0;
}

//Duplicates top of stack
void duplicate(void){
	double storage = pop();
	push(storage);
	push(storage);
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
	//modified version

	//if mark as placed
	//return buf;and remove mark
	//else return getchar()
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else if(c!=EOF)
		buf[bufp++] = c;
	else
		buf[bufp++] = '\n';
	//modified version
	//if not mark as placed
	//buf = c;
	//mark as placed
	//else print error
}

void ungets(char s[]){
	int i;
	i = 0;
	//needs to be in reverse order
	while(s[i++]!='\0')
		;
	--i;
	if( i + bufp < BUFSIZE){
		for(;i>-1; --i)
			ungetch(s[i]);
	} else
		printf("ungets: too many characters\n");
}

int readLine(char charLine[], int max){
	int c, i;
	for(i=0;(c=getchar())!=EOF&& c!='\n'&&i<max-1;i++)
		charLine[i]=c;
	if(c=='\n'){
		charLine[i]=c;
		++i;
	}
	charLine[i]='\0';
	return i;
}

int getop(char *s)
{
	int c, d;
	//4-11 Here
	static int storage = EOF;

	c = (storage!=EOF)?storage:getch();
	if(c==storage)
		storage=EOF;

	while((*s = c) == ' ' || c == '\t')
		c=getch();
	*(s+1) = '\0';
	if(!isalnum(c) && c != '.'  && c!='-'){
		printf("%s", s);
		return c; /*not a number or letter or negative*/
	}
	if(c == '-' ){
		d = getch();
		if(isdigit(d)){
			*(++s)=c=d;
		} else {
			storage = d;
			printf("%s", s);
			return '-';
		}
	}

	if(isalpha(c)){ /*collect letters such as variables or math functions part */
		while(isalpha(*(++s) = c = getch()))
			;
		if(c != EOF)
			storage = c;
		*(++s)='\0';
		return LETTER;
	}


	if(isdigit(c)||c=='-') /*collect integer part*/
		while(isdigit(*(++s) = c = getch()))
			;
	if(c == '.') /*collect fraction part*/
		while(isdigit(*(++s) = c = getch()))
			;
	*s = '\0';
	if(c != EOF)
		storage = c;

	return NUMBER;
}



