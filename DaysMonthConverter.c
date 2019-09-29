/*
 ============================================================================
 Name        : DaysMonthConverter.c
 Author      : Jeffrey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = {
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
};



int day_of_year(int year, int month, int day){
	int i, leap;

	leap = (year%4 ==0 && year%100 != 0) || year%400 == 0;

	if(day>*(*(daytab+leap)+month)){
		printf("Error:exceeded amount of days in month\n");
		printf("Days %d exceed days of the %dth month in the year of %d\n", day, month, year);
		exit(-1);
	}
	if(month > 13){
		printf("Error: exceeded amount of months\n");
		exit(-1);
	}

	for(i = 0; i<month-1; i++)
		day += *(*(daytab+leap)+i%12+1);



	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
	int i, leap;

	leap = (year%4 ==0 && year%100 != 0) || year%400 == 0;
	for(i = 0; yearday > *(*(daytab+leap)+i%12+1); i++)
		yearday -= *(*(daytab+leap)+i%12+1);
	*pmonth = i%12 + 1;
	*pday = yearday;
	if(*pmonth > 12){
		printf("Error: exceeded amount of days\n");

	}
}

int main(void)
{
	int year, month, day, yearday;

	for (year = 1970; year <= 2000; ++year) {
		for (yearday = 1; yearday < 366; ++yearday) {
			month_day(year, yearday, &month, &day);
			if (month <1 || month > 12){
				printf("month_day failed: %d %d\n", year, yearday);
				exit(-1);
			}
			if (day_of_year(year, month, day) != yearday) {
				printf("bad result: %d %d\n", year, yearday);
				printf("month = %d, day = %d\n", month, day);
				exit(-1);
			}
			printf("%d/%d/%d , yearday %d\n", month, day, year, yearday);
		}
	}

	return 0;
}
