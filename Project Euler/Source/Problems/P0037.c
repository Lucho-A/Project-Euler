/*
	Truncatable primes
	Problem 37

	The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

	Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

	13 oct. 2018
 */

#include "libEuler.h"
#define N 11
#define CANT_PRIMES 1500000

bool is_truncable(char *number){
	char strAux[100]={'\0'};
	for(int i=0;i<strlen(number);i++){
		sprintf(strAux, "%.*s", (int) strlen(number), &number[i]);
		if(isPrime(strtol(strAux,NULL,10))==FALSE) return FALSE;
	}
	for(int i=strlen(number);i>=0;i--){
		sprintf(strAux, "%.*s", i, &number[0]);
		if(isPrime(strtol(strAux,NULL,10))==FALSE) return FALSE;
	}
	return TRUE;
}

void P0037(void){
	time_t tInit=clock();
	llu sum=0, cont=0;
	char strPrime[100]={'\0'};
	Vector *vPrimes;
	vInit(&vPrimes);
	generate_vector_of_primes(vPrimes,CANT_PRIMES);
	vGoTo(vPrimes,5);
	while(cont<N){
		sprintf(strPrime,"%Ld", vGetValue(vPrimes));
		if(is_truncable(strPrime)==TRUE){
			printf("%s\n",strPrime);
			sum+=strtol(strPrime,NULL,10);
			cont++;
		}
		vNext(vPrimes);
	}
	time_t tEnd=clock();
	printf("Problem 37 - Result: %Ld. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
