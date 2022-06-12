/*
	Combinatoric selections
  	Problem 53
	Lucho-D
	19 jul. 2020-12:05:04
 */

#include "../../Src/Headers/libEuler.h"
#define LIM_INF 1
#define LIM_SUP 100
#define LIMIT 1000000

void P0053(void){
	time_t tInit=clock();
	double n=LIM_SUP,r=LIM_INF,result=1,cont=0, nAux=0, sum=0;
	for(n=LIM_SUP;n>=LIM_INF;n--){
		nAux=n;
		cont=0;
		result=1;
		for(r=1;r<=n;r++){
			result*=nAux/r;
			nAux--;
			if(result>LIMIT) cont++;
		}
		sum+=cont;
	}
	time_t tEnd=clock();
	printf("Problem P0053 - Result: %.0f. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
