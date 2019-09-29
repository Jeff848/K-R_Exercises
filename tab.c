#include <stdio.h>
#include <stdlib.h>

#define TABLENGTH 8;
int detab(int, int);
void entab(int, int);

int main()
{
	int c, i, hasTabbed, spaceCounter;
	i=hasTabbed=spaceCounter=0;
	while((c=getchar())!=EOF){
		/*
		// 1-20 detab
		if(c=='\t'){
			i+= detab(i,hasTabbed);
			hasTabbed=1;
		} else if(c=='\n'){
			hasTabbed=0;
			putchar(c);
			i=0;
		} else{
			hasTabbed=0;
			putchar(c);
			++i;
		}
		//printf("%d", i);
		 */
		//1-21 entab
		if(c==' '){
			if(spaceCounter==0)
				spaceCounter = 1;
		    else
				++spaceCounter;
		} else if(c=='\n'){
			if(spaceCounter>0){
				entab(spaceCounter, i);
				i+=spaceCounter;
				spaceCounter=0;

			}
			putchar(c);
			i=0;
		} else {
			if(spaceCounter>0){
				entab(spaceCounter, i);
				i+=spaceCounter;
				spaceCounter=0;
			}
			putchar(c);
			++i;
		}
	}
	return 0;
}

int detab(int startingPoint, int first){
	int i,j;
	i = startingPoint;
	i%=TABLENGTH;
	//printf("%d", i);
	j=0;
	while(i< 8&& (i!=0||!first)){
		putchar(' ');
		++i;
		++j;
	}
	return j;
}

void entab(int numSpace, int startingPoint){
	if(numSpace>=8-startingPoint%8 ){
		putchar('\t');
		if(startingPoint%8==0)
			putchar('\t');
		numSpace-=8-startingPoint%8;
	}
	while(numSpace>0){
		if(numSpace>8){
			putchar('\t');
			numSpace-=8;
		} else {
			putchar(' ');
			--numSpace;
		}
	}
}



