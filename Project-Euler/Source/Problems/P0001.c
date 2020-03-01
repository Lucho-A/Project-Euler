/*
	Problem 1

	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
	The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include "libEuler.h"

#define LIMITE 1000

void P0001(void){
    time_t tInit=clock();
    unsigned int i, sum=0;
    for(i=0;i<LIMITE;i++){
    	if((i%3==0 ) || (i%5==0 ) ) sum += i;
    }
    time_t tEnd=clock();
    printf("Problem 1 - Result: %u. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
