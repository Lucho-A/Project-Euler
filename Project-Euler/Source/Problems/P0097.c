/*
	Large non-Mersenne prime
   	Problem 97
	L.
	1 sep. 2019-13:24:39
 */

#include "libEuler.h"
#define MAX_DIG 11
#define EXP 7830457
#define MULTIP 28433

void P0097(void){
	time_t tInit=clock();
	char parcial[MAX_DIG]="0000000002";
	int len=MAX_DIG-2, carry=0, sum=0;
	for(int i=1;i<EXP;i++){
		while(len>=0){
			sum=(parcial[len]-'0') + (parcial[len]-'0') + carry;
			parcial[len]=(sum%10) +'0';
			(sum>9)?(carry=1):(carry=0);
			len--;
		}
		len=MAX_DIG-2;
		carry=0;
	}
	char result[MAX_DIG]="0000000000";
	for(int i=1;i<=MULTIP;i++){
		while(len>=0){
			sum=(parcial[len]-'0')+(result[len]-'0') + carry;
			result[len]=(sum%10) + '0';
			(sum>9)?(carry=1):(carry=0);
			len--;
		}
		len=MAX_DIG-2;
		carry=0;
	}
	char sum1[MAX_DIG]="0000000001";
	while(len>=0){
		sum=(result[len]-'0') + (sum1[len]-'0') + carry;
		result[len]=(sum%10) +'0';
		(sum>9)?(carry=1):(carry=0);
		len--;
	}
	time_t tEnd=clock();
	printf("Problem P0097 - Result: %s. Elapsed Time: %.6f\n",result ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
