/*
 ============================================================================
 Name        : EscapeFunctions.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 100

//3-2 Write a function escape(s,t) that converts chars like newline and tab into
//visible escape sequences like \n and \t as it copies the string t to s.
//Use a switch. Write a function for the other direction
void escape(char output[], char input[]);
void escape2(char output[], char input[]);
void expand(char input[], char output[]);

int main(void) {

	int c, i;
	char currentStr[MAXLINE];
	char outputStr[MAXLINE];
	i=0;
	while((c=getchar())!=EOF){
		currentStr[i++]=c;
		if(c=='\n'){
			currentStr[i]='\0';
			//escape(outputStr,currentStr);
			//escape2(outputStr,currentStr);
			expand(currentStr, outputStr);
			printf("This is the string w/ converted chars: %s", outputStr);

			i=0;
		}
	}
}

void escape(char s[],char t[]){
	int i, j;
	for(i = j = 0; t[i]!='\0'; ++i){
		switch(t[i]){
		case '\t':
			s[j++]='\\';
			s[j++]='t';
			break;
		case '\n':
			s[j++]='\\';
			s[j++]='n';
			break;
		default:
			s[j++]=t[i];
		}
	}
	s[j]='\0';
}

void escape2(char s[],char t[]){
	int i, j;
	for(i = j = 0; t[i]!='\0'; ++i){
		switch(t[i]){
		case '\\':
			switch(t[i+1]){
			case 't':
				s[j++]='\t';
				++i;
				break;
			case 'n':
				++i;
				s[j++]='\n';
				break;
			default:
				s[j++]=t[i];
				break;
			}
			break;
		default:
			s[j++]=t[i];
		}
	}
	s[j]='\0';
}

/*
 * Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into
 * the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared
 * to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally
 */
void expand(char s1[], char s2[]){
	int i, j, k, max;
	for(i=j=0; s1[i]!='\0'; ++i){
		if(isalnum(s1[i])){
			if(s1[i+1]=='-'){
				if(isdigit(s1[i])&&isdigit(s1[i+2])&&s1[i]!=s1[i+2]){
					k=(s1[i]<s1[i+2])?s1[i]:s1[i+1];
					max = (s1[i]>s1[i+2])?s1[i]:s1[i+2];
					for(;k<=max;k++){
						s2[j++]= k;
					}
					++i;
				}
				else if(isalpha(s1[i])&&isalpha(s1[i+2])&&s1[i]!=s1[i+2]){
					k=(s1[i]<s1[i+2])?s1[i]:s1[i+1];
					max = (s1[i]>s1[i+2])?s1[i]:s1[i+2];
					if(max-k>26){
						for(;k<=max-'a'+'Z';k++){
							if(k<='Z')
								s2[j++]=k;
							else
								s2[j++]=k-'Z'+'a'-1;
						}
					} else {
						for(;k<max;k++){
							s2[j++]=k;
						}
					}
					++i;
				} else
					s2[j++]=s1[i];
			}
			else
				s2[j++]=s1[i];
		} else
			s2[j++]=s1[i];
	}
	s2[j]='\0';
}
