#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Takes input and makes a histogram of the input word lengths
 */

int main()
{
	int gymage[] = {30,48,52,25,63,50,18,28,72,25,38,24,48,45,28,39,37,63,20,81,74,21,29,48,37,52,25,44,29,66,32,28,35,49,18,56,48,38,52,33,46,34,44,68,24,34,55,39,40,30};
	int gymgend[] = {0,0,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,0,1,1,0,1,1,1,0,1,1};

	int randNum;
	float proportion;
	for(int i = 0;i<49;i++)
		rand();

	for(int j = 0; j<10; j++){
		proportion = 0;
		for(int z = 0; z<10; z++){
			randNum = gymgend[rand()%50];
			if(randNum)
				proportion++;
		}
		printf("proportion: %f\n", proportion/10);
	}

}



