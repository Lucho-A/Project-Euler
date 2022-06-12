/*
	Integer right triangles
	Problem 39

	If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly
	three solutions for p = 120.

	{20,48,52}, {24,45,51}, {30,40,50}

	For which value of p ≤ 1000, is the number of solutions maximised?

	1 dic. 2018
 */

#include "../../Src/Headers/libEuler.h"
#define N 1001

void P0039(void){
	time_t tInit=clock();
	double h=0;
	int a=0, b=0, result=0, cont=0, maxCont=-1, maxP=0;
	for(int p=1;p<N;p++){
		for(a=1;a<=p;a++){
			for(b=1;b<=a;b++){
				h=sqrt(a*a+b*b);
				if(floor(h)==h){
					result= h + a + b;
					if(result==p) cont++;
				}
			}
		}
		if(cont>maxCont){
			maxCont=cont;
			maxP=p;
		}
		cont=0;
	}
	time_t tEnd=clock();
	printf("Problem 39 - Result: %d. Elapsed Time: %.6f\n",maxP ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
