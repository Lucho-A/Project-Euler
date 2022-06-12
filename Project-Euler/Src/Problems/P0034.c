/*
	Digit factorials
	Problem 34

	145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

	Find the sum of all numbers which are equal to the sum of the factorial of their digits.

	Note: as 1! = 1 and 2! = 2 are not sums they are not included.

	9 oct. 2018
 */

#include "../../Src/Headers/libEuler.h"
#define N (pow(10,5))

void P0034(void){
	time_t tInit=clock();
	char strN[7]={'\0'};
	llu factoriales[10]={0};
	llu sum=0, aux=0;
	for(int i=0;i<10;i++)factoriales[i]=factoriall(i);
	for(llu i=10;i<N;i++){
		aux=0;
		sprintf(strN,"%llu",i);
		for(int j=0;j<strlen(strN);j++){
			aux+=factoriales[strN[j]-'0'];
			if(aux==i)sum+=i;
		}
	}
	time_t tEnd=clock();
	printf("Problem 34 - Result: %Ld. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
