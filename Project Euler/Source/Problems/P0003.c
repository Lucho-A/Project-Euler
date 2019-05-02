/*
	Problem 3

	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143?
*/

#include "libEuler.h"

#define N 600851475143

void P0003(void){
    time_t tInit=clock();
    long int max=0;
    max=maxFactor(N);
    time_t tEnd=clock();
    printf("Problem 3 - Result: %lu. Elapsed Time: %.6f\n",max,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
