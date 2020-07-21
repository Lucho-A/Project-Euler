/*
	Powers of Two
    Problem 686
	Lucho-D
	21 jul. 2020-17:56:41
*/

#include "libEuler.h"
#define BASE "2"
#define L "12"

void P0686(void){
	time_t tInit=clock();
	bool end=FALSE;
	char s1[MAX_DIGIT]=L;
	char r[MAX_DIGIT]="1";
	long int n=1, exp=1;
	char strExp[MAX_DIGIT]="1";
	while(end==FALSE){
		n++;
		exp++;
		sprintf(strExp,"%ld", exp);
		//potencia(BASE, strExp, r);
		/*for(long int i=0; i<strlen(s1);i++){
			end=TRUE;
			if(s1[i]!=r[i]){
				end=FALSE;
				break;
			}
		}*/
		if(exp==3) break;
	}
	time_t tEnd=clock();
	potencia(BASE, strExp, s1);
	printf("%s\n",s1);
	printf("Problem P0686 - Result: %s. Elapsed Time: %.6f\n", r,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
