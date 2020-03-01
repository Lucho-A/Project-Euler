/*
	Digit fifth powers
	Problem 30

	Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 14 + 64 + 34 + 44
    8208 = 84 + 24 + 04 + 84
    9474 = 94 + 44 + 74 + 44

	As 1 = 14 is not a sum it is not included.

	The sum of these numbers is 1634 + 8208 + 9474 = 19316.

	Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

	8 oct. 2018
*/

#include "libEuler.h"
#define MIN_LIMIT 10
#define MAX_LIMIT 354294

void P0030(void){
    time_t tInit=clock();
    char strI[6]={0};
    llu r=0, aux=0;
    for(llu i=MIN_LIMIT;i<MAX_LIMIT;i++){
    	aux=0;
    	sprintf(strI,"%Ld",i);
    	for(int j=0;strI[j]!='\0';j++) aux+=pow(strI[j]-'0',5);
    	if(aux==i) r+=i;
    }
    time_t tEnd=clock();
    printf("Problem 30 - Result: %Ld. Elapsed Time: %.6f\n",r ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
