/*
	How many reversible numbers are there below one-billion?
	Problem 145

	25 may. 2019
 */

#include "libEuler.h"
#define N pow(10,8)

void P0145(void){
	time_t tInit=clock();
	char strI[10]="\0";
	int len=0, isRev=TRUE, cont=0, carry=0, sum=0;
	for(llu i=11;i<N;i++){
		if(i%10==0) continue;
		carry=0;
		isRev=TRUE;
		sprintf(strI,"%llu", i);
		len=strlen(strI);
		for(int j=len-1;j>=0;j--){
			sum=(strI[j] - '0') + (strI[len-1-j] -  '0') + carry;
			carry=0;
			if(sum%2 == 0){
				isRev=FALSE;
				break;
			}
			carry= sum / 10;
		}
		if(carry%2 == 0 && carry!=0) continue;
		if(isRev) cont++;
	}
	time_t tEnd=clock();
	printf("Problem 145 - Result: %d. Elapsed Time: %.6f\n", cont,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
