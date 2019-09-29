/*
 ============================================================================
 Name        : ToyLanguage.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100

int main(){
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
		}
	}

	return 0;
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
