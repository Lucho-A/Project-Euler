/*
	Consecutive positive divisors

	Problem 179

	L
	19 feb. 2020-00:45:56
*/

#include "libEuler.h"
#define N (pow(10,7))

void P0179(void){
	time_t tInit=clock();
	llu crosslimit=N/2;
	llu *vPrimes=malloc(sizeof(llu)*N);
	for(llu i=0;i<N;i++) vPrimes[i]=TRUE;
	for(llu i=2;i<crosslimit;i++){
		if(vPrimes[i]==TRUE){
			for(llu j=i;j*i<N;j++) vPrimes[j*i]=FALSE;
		}
	}
	llu *vPrimes2=NULL;
	generate_vector_of_primes(&vPrimes2,N);
	printf("Vectores generados\n");
	llu expCount=0, cantDiv=1, cantDivAnt=0, contTotal=0, n=0;
	for(llu i=2;i<N;i++){
		if(vPrimes[i]==TRUE) continue;
		n=i;
		cantDiv=1;
		expCount=0;
		for(llu j=0;n!=1;){
			if(n%vPrimes2[j]==0){
				expCount++;
				n/=vPrimes2[j];
				if(n==1) cantDiv*=(expCount+1);
			}else{
				cantDiv*=(expCount+1);
				expCount=0;
				j++;
			}
		}
		if(cantDiv==cantDivAnt){
			//printf("n: %Ld\n", i-1);
			contTotal++;
		}
		cantDivAnt=cantDiv;
	}
	free(vPrimes);
	free(vPrimes2);
	time_t tEnd=clock();
	printf("Problem P0179 - Result: %llu. Elapsed Time: %.6f\n", contTotal,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
