/*
	Totient permutation
	Problem 70

	L
	11 may. 2019-14:18:57
 */

#include "libEuler.h"
#define LIMIT (pow(10,7))

lu qN(lu n){
	lu r=1;
	for(lu i=2;i<n;i++){
		if(gcd(n,i)==1) r++;
	}
	return r;
}

void P0070(void){
	time_t tInit=clock();
	llu qn=0;
	for(llu n=6;n<LIMIT;n++){
		qn=qN(n);
		if(is_permutation_of(n,qN)){
			printf("Rate(%lu/%lu): %f.\n",n,qn, n/qn);
		}
	}
	time_t tEnd=clock();
	printf("Problem P0070 - Result: %lu. Elapsed Time: %.6f\n", qN(87109),(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
