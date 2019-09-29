/*
 ============================================================================
 Name        : Lexer.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Lexer for use with my programming language
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Lexer.h"

int main(void) {
	FILE *inputCode = fopen("input.und","r");
	int i, counter;
	counter = 0;
	token_t initTok[MAXVAL];
	token_t * list = initTok;
	if(inputCode!=NULL){
		while(counter<MAXVAL && (getNextToken(inputCode, list))!=EOF ){

			counter++;
			list++;
		}
		printf("%d\n%d\n" , counter, lineno);


		while(--counter>-1){
			printf("Count %.2d ", counter+1);
			--list;
			if(list->dataType==TOKEN_OP){
				printf("Type: OP " );
				printf("val %c\n", list->val.op);
			}else if(list->dataType==TOKEN_STRING){
				printf("Type: STRING " );
				printf("val %s\n", list->val.string);
			}else if(list->dataType==TOKEN_INT){
				printf("Type: INT " );
				printf("val %d\n", list->val.intval);
			}else if(list->dataType==TOKEN_FLOAT){
				printf("Type: FLOAT " );
				printf("val %f\n", list->val.floatval);
			} else
				printf("Error \n");


		}
		if(counter >= MAXVAL)
			printf("Error: Reached max amount of tokens.");
	}
	i = fclose(inputCode);
	return i;
}

int getNextToken(FILE* filename, token_t * t){
	int c;
	static int storage = EOF;
	c = (storage!=EOF)?storage:fgetc(filename);
	if(c==storage)
		storage=EOF;
	//Skip over blank space
	while(c==' ' || c=='\t' || c == '\n'){
		if(c=='\n') lineno++;
		c = fgetc(filename);
	}
	char * p;

	switch(c){
	case '*':
		t->val.op = '*';
		//printf("%c\n", t->val.op);
		t->dataType = TOKEN_OP;
		return t->dataType;
	case '+':
		t->val.op = '+';
		//printf("%c\n", t->val.op);
		t->dataType = TOKEN_OP;
		return t->dataType;
	case '-':
		t->val.op = '-';
		//printf("%c\n", t->val.op);
		t->dataType = TOKEN_OP;
		return t->dataType;
	case '/':
		t->val.op = '/';
		//printf("%c\n", t->val.op);
		t->dataType = TOKEN_OP;
		return t->dataType;
	case EOF:
		return t->dataType = EOF;
	default:
		p = malloc(MAXSTRING*sizeof(char));
		t->val.string = p;
		*p++ = c;
		if(isdigit(c)||c=='.'){
			//printf("%c %c \n", *t->val.string, c);
			while(isdigit(*p++ = c = fgetc(filename)))
				;//printf("%c %c \n", *t->val.string, c);

			if(c == '.') {
				t->dataType = TOKEN_FLOAT;
				while(isdigit(*p++ = c = fgetc(filename)))
						;//printf("%c", *t->val.string);
				*--p = '\0';
				t->val.floatval = atof(t->val.string);
			}
			else{
				t->dataType = TOKEN_INT;
				*--p = '\0';
				t->val.intval = atoi(t->val.string);
			}
			if(c != EOF)
				storage = c;
			return t->dataType;
		}

		if(isalpha(c)){
			t->dataType = TOKEN_STRING;
			while(isalpha(*(p++) = c = fgetc(filename)))
				;
			//printf("%s\n", p);
			if(c != EOF){
				storage = c;
			}
			*--p ='\0';
			return t->dataType;
		}
		t->val.intval = c;
		return t->dataType = TOKEN_ERROR;
	}

}

