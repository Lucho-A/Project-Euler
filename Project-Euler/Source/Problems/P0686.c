/*
	Powers of Two
    Problem 686
	Lucho-D
	21 jul. 2020-17:56:41
 */

#include "libEuler.h"
//#define N 678910
#define N 2

void P0686(void){
	time_t tInit=clock();
	llu cont=0,j=0, r=2;
	char strN[10000];
	for(j=2;;j++){
		r*=2;
	 	sprintf(strN,"%llu",r);
	 	printf("%s\n",strN);
	 	if(strN[0]=='1' && strN[1]=='2'){
			cont++;
		}
		if(cont==N){
			time_t tEnd=clock();
			printf("Problem P0686 - Result: %llu. Elapsed Time: %.6f\n", j,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
			return;
		}
	}
	return;
}
