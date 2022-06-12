/*
	Circular primes
	Problem 35

	2 may. 2019
*/

#include "../../Src/Headers/libEuler.h"
#define LIMIT 1000000

void P0035(void){
    time_t tInit=clock();
    lu *primes=NULL, result=0;
    lu cant=generate_vector_of_primes(&primes, LIMIT);
    for(int i=0;i<cant;i++){
        if(is_circular_prime(primes[i])==TRUE) result++;
    }
    time_t tEnd=clock();
    printf("Problem 35 - Result: %lu. Elapsed Time: %.6f sec's\n", result,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}


