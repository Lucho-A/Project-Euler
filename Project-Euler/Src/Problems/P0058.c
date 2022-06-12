/*
	Spiral primes
   	Problem 58

	19 ago. 2019
 */

#include "../../Src/Headers/libEuler.h"

void P0058(void){
	time_t tInit=clock();
	lu c=0, incr=2, cVert=0, cPrimes=0, sideLenght=3;
	double ratio=0.0;
	for(llu i=3;;i+=incr){
		if(is_prime(i)==TRUE) cPrimes++;
		c++;
		cVert++;
		if(cVert==4){
			ratio = (double) (cPrimes/((double) c+1)) * 100;
			if(ratio<10.0){
				time_t tEnd=clock();
				printf("Problem 58 - Result: %lu (%.6lf). Elapsed Time: %.6f\n",sideLenght, ratio,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
				return;
			}
			cVert=0;
			incr+=2;
			sideLenght+=2;
		}
	}
}
