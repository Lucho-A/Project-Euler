/*
	Prime permutations
	Problem 49

	L
	11 may. 2019-13:01:41
 */

#include "../../Src/Headers/libEuler.h"
#define N 10000
#define INCR 3330

void P0049(void){
	time_t tInit=clock();
	lu *vPrimes=NULL, cantPrimes=0, n2=0, n3=0;
	cantPrimes=generate_vector_of_primes(&vPrimes, N);
	for(int i=0;i<cantPrimes;i++){
		n2=vPrimes[i]+INCR;
		n3=vPrimes[i]+INCR*2;
		if(vPrimes[i]>999 && vPrimes[i]!=1487 && is_prime(n2) && is_prime(n3)){
			if(is_permutation_of(vPrimes[i],n2) && is_permutation_of(vPrimes[i],n3)){
				time_t tEnd=clock();
				printf("Problem P0049 - Result: %lu%lu%lu. Elapsed Time: %.6f\n", vPrimes[i],n2,n3,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
			}
		}
	}
	return;
}
