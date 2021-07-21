/*
	Square root convergents
	Problem 57
	L.
	31 ago. 2019-16:30:04
 */

#include "libEuler.h"
#define N 1000

void P0057(void){
	time_t tInit=clock();
	char p[N][N]={{"\0"}}, q[N][N]={{"\0"}};
	lu sum=0;
	strcpy(p[0],"1");
	strcpy(q[0],"1");
	strcpy(p[1],"3");
	strcpy(q[1],"2");
	for(lu i=2;i<N;i++){
		sum_big_numbers(p[i-1],p[i-1],p[i]);
		sum_big_numbers(p[i],p[i-2],p[i]);
		sum_big_numbers(q[i-1],q[i-1],q[i]);
		sum_big_numbers(q[i],q[i-2],q[i]);
		if(strlen(p[i])>strlen(q[i])) sum++;
	}
	time_t tEnd=clock();
	printf("Problem P0057 - Result: %lu. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
