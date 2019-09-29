#include <stdio.h>
#include <stdlib.h>
/*Takes input and makes a histogram
 */
void histogramMaker(int input[]);

int main()
{
	int c;
	int newWord, i;
	int nchar[64]; //For making a histogram with # of char
	i = newWord = 0;

	for(; i<64; i++){
		nchar[i]=0;
	}

	while((c=getchar())!=EOF){
		if(c==' '||c=='\n'||c=='\t')
			++nchar[62];
		else if(c>='0'&&c<='9')
			++nchar[c-'0'];
		else if(c>='A'&&c<='Z')
			++nchar[c-'A'+10];
		else if(c>='a'&&c<='z')
			++nchar[c-'a'+36];
		else
			++nchar[63];
	}

	histogramMaker(nchar);


	return 0;
}

void histogramMaker(int input[]){
	int max, i, arrayMax;
	max = i = 0;
	arrayMax = 64;

	printf("Here is the horz histogram\n");
	for(; i<arrayMax;i++){
		if(i<10){
			putchar(i+'0');
		} else if(i<36){
			putchar(i+'A'-10);
		} else if(i<62){
			putchar(i+'a'-36);
		} else if(i<63){
			putchar('\\');
		} else{
			putchar('?');
		}
		putchar(' ');
		for(int j = 0; j<input[i];j++){
			printf("x");
		}
		printf("\n");
		if(input[i]>max)
			max = input[i];
	}

	printf("Here is the vertical one\n");
	for(i=max; i>0; i--){
		for(int j = 0; j<arrayMax; j++){
			if(input[j]>=i)
				printf("x");
			else
				printf(" ");

		}
		printf("\n");
	}
	for(i=0; i<arrayMax;i++){
			if(i<10){
				putchar(i+'0');
			} else if(i<36){
				putchar(i+'A'-10);
			} else if(i<62){
				putchar(i+'a'-36);
			} else if(i<63){
				putchar('\\');
			} else{
				putchar('?');
			}
	}
}


