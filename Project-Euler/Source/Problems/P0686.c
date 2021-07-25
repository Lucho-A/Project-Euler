/*
	Powers of Two
    Problem 686
	Lucho-D
	21 jul. 2020-17:56:41
 */

#include "libEuler.h"
#define N 678910
//#define N 45

void P0686(void){ // VER CON LOGARITMOS (https://www.geeksforgeeks.org/find-the-first-and-last-m-digits-from-k-th-power-of-n/)
	time_t tInit=clock();
	int cont=0,j=0, len=0, sum=0, carry=0;
	char strN[100000]="2";
	for(j=2;;j++){
		len=0;
		carry=0;
		while(len<strlen(strN)){
			sum=((strN[len] - '0') * 2 + carry);
			strN[len]=(sum % 10) + '0';
			(sum>9)?(carry=1):(carry=0);
			len++;
		}
		if(carry==1) strN[len]='1';
		if(strN[strlen(strN)-1]=='1' && strN[strlen(strN)-2]=='2' && strN[strlen(strN)-3]=='3'){
		//if(strN[strlen(strN)-1]=='1' && strN[strlen(strN)-2]=='2'){
			cont++;
			//printf("%s\n",strN);
			printf("%d\n",cont);
			if(cont==N){
				time_t tEnd=clock();
				printf("Problem P0686 - Result: %llu. Elapsed Time: %.6f\n", j,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
				return;
			}
		}
	}
	return;
}
