/*
	Consecutive positive divisors

	Problem 179

	L
	19 feb. 2020-00:45:56
 */

#include "libEuler.h"
#define N 10000000

void P0179v1(void){
	time_t tInit=clock();
	llu *vPrimes=NULL;
	llu count=1, cantDiv=1, cantDivAnt=0, contTotal=1,n=0,j=0;
	generate_vector_of_primes(&vPrimes,N/2);
	for(llu i=1;i<N;i++){
		n=i;
		count=0;
		cantDiv=1;
		if(is_prime(n)==FALSE && n!=1){
			for(j=0;n!=1;){
				if(n%vPrimes[j]==0){
					count++;
					n/=vPrimes[j];
					if(n==1) cantDiv*=(count+1);
				}else{
					cantDiv*=(count+1);
					count=0;
					j++;
				}
			}
		}else{
			cantDiv++;
		}
		printf("Valor de %llu: %llu\n",i ,cantDiv);
		if(cantDiv==cantDivAnt) contTotal++;
		cantDivAnt=cantDiv;
	}
	time_t tEnd=clock();
	printf("Problem P0179 - Result: %llu. Elapsed Time: %.6f\n", contTotal,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
