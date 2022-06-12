/*
	Pandigital multiples
	Problem 38

	Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

	By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576
	the concatenated product of 192 and (1,2,3)

	The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital,
	918273645, which is the concatenated product of 9 and (1,2,3,4,5).

	What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer
	with (1,2, ... , n)
	where n > 1?
	1 dic. 2018
 */

#include "../../Src/Headers/libEuler.h"
#define N

void P0038(void){
	time_t tInit=clock();
	char pandigital[15]="\0";
	char aux='\0';
	int i, j, k, l, isP=FALSE;
	llu auxPandigital=0, maxPandigital=0;
	for(i = 1;i*2<99999;i++){
		sprintf(pandigital,"%s", "\0");
		isP=TRUE;
		for(j=1;;j++){
			if(strlen(pandigital)>=9) break;
			sprintf(pandigital,"%s%d", pandigital,i*j);
			auxPandigital=strtoul(pandigital, NULL,10);
			if(strlen(pandigital)==9 && auxPandigital>maxPandigital){
				for(k=0;k<8 && isP==TRUE;k++){
					for(l=k+1;l<9;l++){
						if(pandigital[k]>pandigital[l]){
							aux=pandigital[k];
							pandigital[k]=pandigital[l];
							pandigital[l]=aux;
						}
					}
					if(pandigital[k]!=((k+1) +'0')){
						isP=FALSE;
						break;
					}
				}
				if(isP)maxPandigital=auxPandigital;
			}
		}
	}
	time_t tEnd=clock();
	printf("Problem 38 - Result: %Lu. Elapsed Time: %.6f\n",maxPandigital ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
