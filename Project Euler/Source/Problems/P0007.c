/*
Problem 7
	28 December 2001

	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

	What is the 10001st prime number?
*/

#include "libEuler.h"

#define N 10001

void P0007(void){
    time_t tInit=clock();
    int cont=1,i=3;
    while(TRUE){
    	if(isPrime(i)) cont++;
    	if(cont==N) break;
    	i+=2;
    }
    time_t tEnd=clock();
    printf("Problem 7 - Result: %d. Elapsed Time: %.6f\n",i,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
