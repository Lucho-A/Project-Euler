/*
Consecutive prime sum
Problem 50

The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains
21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

13 ago. 2018
*/

#include "../../Src/Headers/libEuler.h"
#define N 1000000

void P0050(void){
    time_t tInit=clock();
    int maxN=0, maxCont=0, size=0, n=0, cont=0;
    Vector *v=NULL;
    vInit(&v);
    generate_vector_of_primes(v,N);
    size=vGetSize(v);
	int *vPrimes=malloc(sizeof(int)*size);
	do{
		vPrimes[cont]=vGetValue(v);
		cont++;
	}while(vNext(v));
	free(v);
	cont=1;
	for(int i=0;i<size-1;i++){
		n=vPrimes[i];
		for(int j=i+1;j<size && n<N;j++){
			if(is_prime(n)){
				if(cont>maxCont){
					maxN=n;
					maxCont=cont;
				}
			}
			cont++;
			n+=vPrimes[j];
		}
		cont=1;
	}
    time_t tEnd=clock();
    printf("Problem 50 - Result: %d (%d). Elapsed Time: %.6f\n",maxN,maxCont,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
