/*
 ============================================================================
 Name        : Recursion.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define swap(t,x,y) t temp = x; x = y; y = temp;

void itoa(char[],int);
int recursiveitoa(char[],int,int);
void reverse(char[],char[]);
int recursivereverse(char[],char[],int);

int main(void) {
	char characters[] = "Help me!!!";
	char output[100];
	reverse(characters,output);
	printf("%s", output);
	int x = 1;
	int y = 2;
	swap(int, x, y)
	printf("%d %d", x, y);

	return EXIT_SUCCESS;
}

void itoa(char s[], int given){
	int i = 0;
	if(given<0){
		s[i++]='-';
		given = -given;
	}
	i = recursiveitoa(s,given,i);
	s[i]='\0';
}

int recursiveitoa(char s[], int given, int index){
	int i;
	if(given/10){
		i = recursiveitoa(s,given/10,index);
		s[i]=given%10+'0';
		return i + 1;
	}
	s[index] = given%10+'0';
	return index + 1;
}

void reverse(char s[], char temp[]){
	int i;
	i = recursivereverse(s,temp,0);
	temp[i]='\0';
}

int recursivereverse(char s[], char temp[], int toIndex){
	int i;
	i = -1;
	if(s[toIndex]!='\0'){
		i = recursivereverse(s,temp,toIndex+1);
		temp[i]=s[toIndex];
	}
	return i+1;
}

