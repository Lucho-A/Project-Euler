/*
Summation of primes
Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include "libEuler.h"

#define N 2000000

void P0010(void){
    time_t tInit=clock();
    llu sum=0;
    Vector *vectorPrimes;
    vInit(&vectorPrimes);
    generate_vector_of_primes(vectorPrimes,N);
    vFirst(vectorPrimes);
    do{
    	sum+=vGetValue(vectorPrimes);
    }while(vNext(vectorPrimes)!=NULL);
    time_t tEnd=clock();
    printf("Problem 10 - Result: %llu. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
