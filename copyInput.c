#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define ARBITRARY 10
int readLine(char line[],int maxline);
void copyLine(char from[],char to[],int len);
void reverse(char string[]);
void removeTrailingSpace(char string[]);
int strrindex(char[], char[]);

int main()
{
	int len, max;

	char currentLine[MAXLINE];
	char mostLengthLine[MAXLINE];
	max = 0;
	while((len=readLine(currentLine,MAXLINE))>0){

		printf("%d", strrindex(currentLine, "help"));
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
void copyLine(char initLine[], char newLine[], int length){
	newLine[length-1]='\0';
	for(--length;length>0; --length){
		newLine[length-1]=initLine[length-1];
	}
}
void reverse(char s[]){
	int i, len;
	i = 0;
	while(s[i]!='\n'){
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
void removeTrailingSpace(char s[]){
	int i, whiteSpaceCounter, first;
	whiteSpaceCounter = first = 1;
	for(i=0;s[i]!='\0';++i){
		if(s[i]==' '||s[i]=='\t'||s[i]=='\n'){
			if(first){
				whiteSpaceCounter=i;
				first = 0;
			}
		}else{
			first = 1;
		}
	}
	s[whiteSpaceCounter+1] = '\0';
	if(whiteSpaceCounter!=0)
		s[whiteSpaceCounter] = '\n';
	else
		s[whiteSpaceCounter] = '\0';
}

/*
 * Exercise 4-1
 * Write the function strrindex(s,t) which returns the position of the rightmost occurrence of t
 * in s, or -1 if there is none
 */
int strrindex(char s[], char t[]){
	int i, j, storage;
	storage = -1;
	for(i = 0; s[i]!='\0';++i){
		if(s[i]==t[0]){
			for(j=1;s[i+j]==t[j]&&s[i+j]!='\0'&&t[j]!='\0';++j)
				;
			if(t[j]=='\0')
				storage = i;
		}
	}
	return storage;
}


