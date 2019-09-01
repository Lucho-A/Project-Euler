/*
	Powerful digit sum
	Problem 56
	L.
	1 sep. 2019-02:53:09
 */

#include "libEuler.h"
#define LIMIT	100

void vInit0(char *v){
	for(int i=0;i<5000;i++) v[i]='\0';
}

void P0056(void){
	time_t tInit=clock();
	char result[5000]={"\0"}, base[LIMIT]={"\0"}, exp[LIMIT]={"\0"};
	lu sum=0, maxSum=0;
	for(int a=2;a<LIMIT;a++){
		for(int b=1;b<LIMIT;b++){
			vInit0(result);
			sprintf(base,"%d",a);
			sprintf(exp,"%d",b);
			potencia(base,exp,result);
			for(int i=0;i<strlen(result);i++) sum+=result[i] - '0';
			if(sum>maxSum) maxSum=sum;
			sum=0;
		}

	}
	time_t tEnd=clock();
	printf("Problem P0056 - Result: %lu. Elapsed Time: %.6f\n", maxSum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
