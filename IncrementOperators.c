/*
 ============================================================================
 Name        : IncrementOperators.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLIMIT 100

void squeeze(char[],char[]);
int any(char[],char[]);



int main(void) {
	int c, i;
	char input[MAXLIMIT], comparison[MAXLIMIT];
	i=0;
	while((c=getchar())!='\n'){
		input[i++]=c;
	}
	input[i]='\0';
	i=0;
	while((c=getchar())!='\n'){
		comparison[i++]=c;
	}
	comparison[i]='\0';
	i= any(input, comparison);
	squeeze(input, comparison);
	printf("Squeeze result: %s\n", input);
	printf("Any result: %d", i);
	return EXIT_SUCCESS;

}

void squeeze(char s1[], char s2[]){
	int i, j, k;

	for(i=j=0;s2[i]!='\0';++i){
		for(k=j+1; s2[k]!='\0';++k){
			if(s2[k]==s2[j])
				++j;
		}
		s2[i]=s2[j++];
	}
	s2[j]='\0';
	//printf("%s", s2);
	for(i=j=0; s1[i]!='\0';++i){
		for(k=0; s2[k]!='\0';++k){
			if(s1[j]==s2[k])
				++j;
		}
		s1[i]=s1[j++];
	}
	s1[j]='\0';
}

int any(char s1[], char s2[]){
	int i, k;
	for(i=0; s1[i]!='\0';++i){
		for(k=0; s2[k]!='\0';++k){
			if(s1[i]==s2[k])
				return i;
		}
	}
	return -1;
}
