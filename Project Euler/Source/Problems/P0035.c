/*

	2 may. 2019
*/

#include "libEuler.h"
#define LIMIT 100

void P0035(void){
    time_t tInit=clock();
    //long unsigned int primes[LIMIT]={0};
    lu *primes=NULL;
    lu cant=generate_vector_of_primes(&primes, LIMIT);
    for(int i=0;i<cant;i++){
    	printf("Primo: %lu\n",primes[i]);
    }
	//TODO

    time_t tEnd=clock();
    printf("Problem 35 - Result: %f. Elapsed Time: %.6f\n", 0.0,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
