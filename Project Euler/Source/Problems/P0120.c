/*
	Square remainders
	Problem 120

	L
	15 may. 2019-20:42:43
 */

#include "libEuler.h"
#define LIMIT_MAX_a 1000
#define LIMIT_MIN_a 3
#define EQ	((llu)(pow((a-1),n) + pow((a+1),n)))

void P0120(void){
	time_t tInit=clock();
	llu a=0, n=0, r=0, cont=0, maxR=0, result=0;
	for(a=LIMIT_MIN_a;a<=LIMIT_MAX_a;a++){
		cont=0;
		maxR=0;
		for(n=0;;n++){
			r=EQ%(a*a);
			if(maxR<r) maxR=r;
			(r==0)?(cont++):(cont=0);
			if(cont==5){
				printf("a: %llu, n: %llu, r: %llu, maxR: %llu\n",a,n,r, maxR);
				result+=maxR;
				break;
			}
		}
	}
	time_t tEnd=clock();
	printf("Problem P0120 - Result: %Lf. Elapsed Time: %.6f\n", result,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
