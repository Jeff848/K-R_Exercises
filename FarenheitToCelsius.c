/*
Tutorial on basics of C.
 */

#include <stdio.h>
#include <stdlib.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

float convertFahrToCelsius(float);

int main() {
	//int fahr, celsius;
	float fahr, celsius;
	fahr = LOWER;
	printf("From degrees Fahrenheit to Celsius [0 to 300]\n");
	while(fahr <= UPPER){
		printf("%3.0f\t%3.1f\n", fahr, convertFahrToCelsius(fahr));
		fahr+=STEP;
	}

	printf("But now in reverse!\n");
	for(fahr=UPPER; fahr>=LOWER; fahr-=STEP){
			printf("%3.0f\t%3.1f\n", fahr, convertFahrToCelsius(fahr));;
	}

	printf("From degrees Celsius to Fahrenheit [-20 to 120]\n");
	celsius = -20;
	while(celsius <= 120){
		fahr = 9 * (celsius)/5 +32;
		printf("%3.0f\t%3.1f\n", celsius, fahr);
		celsius+=10;
	}




}
float convertFahrToCelsius(float fahr){
	float celsius;
	celsius = 5 * (fahr-32)/9;
	return(celsius);
}

