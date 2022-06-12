/*
 	"Convergents of e"
 	P0065.c
	Lucho-D
	27 ene. 2022-10:56:39
*/

#include "libEuler.h"
#define LIMIT 100
#define MAX_DIG 75

void P0065(void){
	time_t tInit=clock();
	long double index[LIMIT]={1};
	for(int i=0;i<LIMIT;i++) index[i]=1;
	long int cont=1, sum=0;
	for(int i=1;i<LIMIT;i+=3, cont++) index[i]=cont*2;
	char aux[MAX_DIG]="1", r[MAX_DIG]="2", nAnt[MAX_DIG]="1";
	for(int i=0;i<LIMIT-1;i++){
		strcpy(aux,r);
		for(int j=1;j<index[i];j++) sum_big_numbers(r, aux, r);
		sum_big_numbers(r, nAnt, r);
		strcpy(nAnt, aux);
	}
	for(int i=0; i<strlen(r);i++) sum+=r[i]-'0';
	time_t tEnd=clock();
	printf("Problem P0065 - Result: %.0ld (%s). Elapsed Time: %.6f\n", sum, r,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
