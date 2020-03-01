/*
	Large non-Mersenne prime
   	Problem 97
	L.
	1 sep. 2019-13:24:39
*/

#include "libEuler.h"

void P0097(void){
	time_t tInit=clock();
	char *result=malloc(sizeof(char)*MAX_DIGIT);
	for(lu i=0;i<MAX_DIGIT;i++) result[i]='\0';
	//potencia("2","7830457", result);
	potencia("2","8", result);
	time_t tEnd=clock();
	printf("Problem P0097 - Result: %s. Elapsed Time: %.6f\n",result ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
