/*
	Largest exponential

	Problem 99

	L.

	16 nov. 2021
*/

#include "../../Src/Headers/libEuler.h"

void P0099(void){
	time_t tInit=clock();
	long int maxLine=1, contLine=1;
	double maxValue=0.0, base=0.0, exp=0.0, r=0.0;
	FILE *f=NULL;
	if((f=fopen("Resources/P0099/p099_base_exp.txt","r"))==NULL) exit(EXIT_FAILURE);
	while(fscanf(f,"%lf,%lf",&base,&exp)!=EOF){
		r=exp*log10(base);
		if(r>maxValue){
			maxValue=r;
			maxLine=contLine;
		}
		contLine++;
	}
	time_t tEnd=clock();
	printf("Problem 99 - Result: %ld. Elapsed Time: %.6f\n", maxLine,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
