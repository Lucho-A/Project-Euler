/*
	Pandigital products
	Problem 32

	We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

	The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

	Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
	HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

	9 oct. 2018
 */

#include "../../Src/Headers/libEuler.h"
#define N

void P0032(void){
	time_t tInit=clock();
	int result=0, sum=0, results[50]={0},index=0, len=0, esP=FALSE;;
	char strI[10]={"\0"},strJ[10]={"\0"}, strResult[10]={"\0"}, strP[30]={"\0"};
	char aux;
	for(int i=1;i<99;i++){
		for(int j=i;j<9999;j++){
			esP=TRUE;
			result=i*j;
			sprintf(strResult,"%d",result);
			sprintf(strI,"%d",i);
			sprintf(strJ,"%d",j);
			sprintf(strP,"%s%s%s", strI,strJ,strResult);
			len=strlen(strP);
			if(len!=9) continue;
			if(len==9){
				for(int i=0; i<len-1;i++){
					for(int j=i+1; j<len;j++){
						if(strP[i]>strP[j]){
							aux=strP[i];
							strP[i]=strP[j];
							strP[j]=aux;
						}
					}
					if(strP[i]!=(i+1)+'0'){
						esP=FALSE;
						break;
					}
				}
				if(strP[8]!='9') esP=FALSE;
				if(esP==TRUE){
					results[index]=result;
					index++;
				}
			}
		}
	}
	int intAux=0;
	for(int i=0;i<49;i++){
		for(int j=i+1;j<50;j++){
			if(results[i]<results[j]){
				intAux=results[i];
				results[i]=results[j];
				results[j]=intAux;
			}
		}
	}
	for(int i=0;i<50;i++){
		if(results[i]!=results[i-1]) sum +=results[i];
	}
	time_t tEnd=clock();
	printf("Problem 32 - Result: %d. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
