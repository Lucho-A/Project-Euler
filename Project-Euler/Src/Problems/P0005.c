/*
	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without
	any remainder.

	What is the smallest number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include "libEuler.h"
#define N 20

void P0005(void){
    llu n=1, i=1;
    bool check=TRUE;
    int limit=sqrt(N);
    Vector * vectorPrimes;
    vInit(&vectorPrimes);
    generate_vector_of_primes(vectorPrimes,N * 2);
    llu *a=malloc(sizeof(llu)*vGetSize(vectorPrimes));
    for(int i=0;i< vGetSize(vectorPrimes);i++) a[i]=0;
    vGoTo(vectorPrimes,i-1);
    while(vGetValue(vectorPrimes)<=N){
    	a[i]=1;
    	if(check){
    		if(vGetValue(vectorPrimes)<=limit){
    			a[i]=floor(log(N)/log(vGetValue(vectorPrimes)));
    		}else{
    			check=FALSE;
    		}
    	}
    	printf("n= %llu. a[i]= %llu\n", vGetValue(vectorPrimes), a[i]);
    	n *= pow(vGetValue(vectorPrimes), a[i]);
    	i++;
        vGoTo(vectorPrimes,i-1);
    }
    return;
}
