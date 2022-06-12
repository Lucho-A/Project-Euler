/*
Summation of primes
Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include "libEuler.h"

#define N 2000000

llu P0010(void){
    llu sum=0;
    Vector *vectorPrimes;
    vInit(&vectorPrimes);
    generate_vector_of_primes(vectorPrimes,N);
    vFirst(vectorPrimes);
    do{
    	sum+=vGetValue(vectorPrimes);
    }while(vNext(vectorPrimes)!=NULL);
    return sum;
}
