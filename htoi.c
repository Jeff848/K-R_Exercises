/*
 ============================================================================
 Name        : HexToInt.c
 Author      : Jeffrey
 Version     :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int htoi(char[]);

int main(void) {
	char input[100], flag;
	int c, i;
	i = flag = 0;

	while((c=getchar())!='\n'){
		input[i]=c;
		++i;
		if(c=='0'){
			c=getchar();
			++i;
			if(c=='x'||c=='X')
				flag=1;
		}
	}
	input[i]='\0';
	if(flag)
		printf("Your hexadecimal number: %s, the decimal equivalent: %d", input, htoi(input));

	return EXIT_SUCCESS;
}

int htoi(char s[]){
	int i, answer, multiplier;
	answer=0;
	multiplier=1;
	for(i=0;s[i]!='\0';++i)
		;
	--i;
	//printf("%d\n",i);
	for(;i>1;--i){
		if(isdigit(s[i]))
			answer+=multiplier * (s[i]-'0');
		else if(s[i]>='a'&&s[i]<='f')
			answer+=multiplier * (10+s[i]-'a');
		else if(s[i]>='A'&&s[i]<='F')
			answer+=multiplier * (10+s[i]-'A');
		multiplier*=16;
		//printf("%d\n",answer);
	}
	return answer;
}
