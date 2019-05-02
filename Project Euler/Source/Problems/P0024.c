/*
	Lexicographic permutations
	Problem 24

	A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
	If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
	The lexicographic permutations of 0, 1 and 2 are:

		012   021   102   120   201   210

	What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

	26 sep. 2018
 */

#include "libEuler.h"
#define N 1000000

void P0024(void){
	time_t tInit=clock();
	char s[10]="0123456789", sAux=' ';
	llu k=0,l=0, count=1, len=strlen(s);
	while(count!=N){
		k=-1;
		for(int i=0;i<len;i++) if(s[i]<s[i+1]) k=i;
		if(k==-1) break;
		for(l=len-1;l>=0;l--) if(s[k]<s[l]) break;
		sAux=s[k];
		s[k]=s[l];
		s[l]=sAux;
		for(int i=k+1;i<len-1;i++){
			for(int j=i+1;j<len;j++){
				if(s[i]>s[j]){
					sAux=s[i];
					s[i]=s[j];
					s[j]=sAux;
				}
			}
		}
		count++;
	}
	time_t tEnd=clock();
	printf("Problem 24 - Result: %s. Elapsed Time: %.6f\n",s,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
