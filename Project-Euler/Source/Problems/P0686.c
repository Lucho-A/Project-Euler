/*
	Powers of Two
    Problem 686
	Lucho-D
	21 jul. 2020-17:56:41
*/

#include "libEuler.h"
#define BASE "2"
#define N 15

void P0686(void){
	time_t tInit=clock();
	char r[MAX_DIGIT]="1";
	ld cont=0;
	for(ld j=2;;j++){
		for(int i=0;i<MAX_DIGIT;i++)r[i]='\0';
		potencia(BASE, j, r);
		if(r[0]=='1' && r[1]=='2' && r[2]=='3') cont++;
		if(cont==N){
			time_t tEnd=clock();
			printf("Problem P0686 - Result: %ld (%s). Elapsed Time: %.6f\n", j, r,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
			return;
		}
	}
	return;
}
