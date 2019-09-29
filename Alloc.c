/*
 ============================================================================
 Name        : Alloc.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#define MAXLINES 500
#define MAXLEN 1000
#define MAXSTORE 1000


char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *ls);
void writelines(char *lineptr[], int nlines);
int readLine(char[], int);
void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    char linestore[MAXSTORE]; /* array for storing all lines */

    if ((nlines = readlines(lineptr, MAXLINES, linestore)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}




int readlines(char *lineptr[], int maxlines, char *ls)
{
   int len, nlines;
   char *p, line[MAXLEN];
   char *reference = ls;
   nlines = 0;
   p = ls;
   while((len = readLine(line, MAXLEN))>0){
	   if(nlines >= maxlines || (ls - reference) + len > MAXSTORE){
		   return -1;
	   } else {
		   line[len-1] = '\0';
		   strcpy(p, line);
		   lineptr[nlines++] = p;
		   ls += len;
		   p = ls;
	   }
   }
   return nlines;
}

/* K&R2 p98 */

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* K&R2 p97 */

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


int readLine(char* charLine, int max){
	int c, i;
	for(i=0;(c=getchar())!=EOF&& c!='\n'&&i<max-1;i++)
		*(charLine+i)=c;
	if(c=='\n'){
		*(charLine+i)=c;
		++i;
	}
	*(charLine+i)='\0';
	return i;
}
