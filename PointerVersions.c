/*
 ============================================================================
 Name        : PointerVersions.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>

#define MAXLINE 100

void stringcat(char *s, char *t);
int strend(char *s, char *t);
char *stringncpy(char *s,char *ct,size_t n);
char *stringncat(char *s,char *ct,size_t n);
int stringncmp(char *cs, char *ct, size_t n);

int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	/*
	char string1[MAXLINE] = "Help me";
	char phone1[MAXLINE] = "sphinx of b";
	char string2[MAXLINE] = "Help me";
	char phone2[MAXLINE] = "sphinx of b";
	//printf("%s\n",string);
	//stringcat(string, phone);
	//printf("%s",string);
	strncpy(string1, phone1, 5);
	stringncpy(string2, phone2, 5);

	char str1[]= "To be or not to be";
	char str2[40];
	char str3[40];

	//copy to sized buffer (overflow safe):
	stringncpy ( str2, str1, sizeof(str2) );

	//partial copy (only 5 chars):

	stringncpy ( str3, str2, 5 );

	printf("%s\n%s\n%s\n",str1,str2,str3);

	printf("%s\n", string1);
	printf("%s\n", string2);
	*/
	/*
	char str1[20];
	char end1[20];
	char str2[20];
	char end2[20];
	strcpy (str1,"To be ");
	strcpy (end1,"or not to be");
	strcpy (str2,"To be ");
	strcpy (end2,"or not to be");
	strncat (str1, end1, 6);
	stringncat(str2,end2, 6);
	printf("%s\n%s",str1, str2);
	*/
	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
	int n;
	puts ("Looking for R2 astromech droids...");
	for (n=0 ; n<3 ; n++)
		if (stringncmp (str[n],"R2xx",2) == 0)
	    {
			printf ("found %s\n",str[n]);
	    }

	return 0;
}

/*
 * Exercise 5-3
 * Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string
 * t to the end of s
 */

void stringcat(char *s, char *t){
	while(*s)
		s++;
	while((*s++=*t++))
		;
}

/*
 * Exercise 5-4
 * Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and
 * zero otherwise.
 */
int strend(char *s, char *t){
	while(*s && *s!=*t)
		s++;
	while(*s && *s==*t){
		s++;
		t++;
	}
	if(!*t&&!*s)
		return 1;
	return 0;
}

/*
 * Exercise 5-5
 * Write versions of the library functions strncpy, strncat and strncmp, which operate on at most the first
 * n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characers of t to s
 */

char *stringncpy(char *s, char *ct, size_t n){
	int i = 1;
	while((*s++=*ct++)&& i++<n)
			;
	while((*s++='\0'))
		;
	return s;
}

char *stringncat(char *s, char *ct, size_t n){
	while(*s)
		s++;
	int i = 1;
	while((*s++=*ct++)&& i++<n)
			;
	*s='\0';
	return s;
}
int stringncmp(char *cs, char *ct, size_t n){
	int i = 1;
	while(*cs && *cs==*ct && i++<n){
		cs++;
		ct++;
	}
	return *cs-*ct;
}

/*
 * Exercise 5-6
 * Rewrite appropriate programs from earlier chcapters and exercises with pointers instead of arrays
 * Good possibilities include getline, atoi, itoa, reverse, and strindex, getop
 */


