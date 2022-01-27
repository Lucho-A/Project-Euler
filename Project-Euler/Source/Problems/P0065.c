/*
 	"Convergents of e"
 	P0065.c
	Lucho-D
	27 ene. 2022-10:56:39
*/

#include "libEuler.h"

void P0065(void){
	time_t tInit=clock();
	long double index[100]={0}, nAnt1=1, aux=0, r=2;
	for(int i=0;i<100;i++) index[i]=1;
	int cont=1;
	for(int i=1;i<100;i+=3, cont++)index[i]=cont*2;
	for(int i=0;i<100;i++){
		aux=r;
		r=r*index[i]+nAnt1;
		nAnt1=aux;
		printf("r: %lf\n", r);
	}

	time_t tEnd=clock();
	printf("Problem P0065 - Result: %f. Elapsed Time: %.6f\n", 0.0,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
