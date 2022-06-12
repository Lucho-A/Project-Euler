/*
	Prime square remainders
	Problem 123
	25 ago. 2019-10:17:27
*/

#include "../../Src/Headers/libEuler.h"
#define LIMIT (pow(10,9))
#define Q_PRIMES 150000
#define EQ(n,p) ((double)(pow(p-1,n)+pow(p+1,n))) //%(p*p))

long double eq(double n, double p){
	return fmodl((powl(p-1,n)+powl(p+1,n)),powl(p,2));
}

void P0123(void){
	time_t tInit=clock();
	llu *vPrimes=NULL, qPrimes=generate_vector_of_primes(&vPrimes,Q_PRIMES);
	long double r=0.0;
	printf("#: %llu\n",qPrimes);
	for(llu n=0;n<qPrimes;n++){
		r=eq(n+1,vPrimes[n]);
		//if(r>LIMIT){
		if(n+1==7037){
			printf("Primo n°%llu: %llu --> %.Lf\n",n+1,vPrimes[n], r);
			time_t tEnd=clock();
			printf("Problem P0123 - Result: %llu. Elapsed Time: %.6f\n", n+1,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
			return;
		}
	}
	//printf("Problem P0123.c - Result: %f. Elapsed Time: %.6f\n", 0.0,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}