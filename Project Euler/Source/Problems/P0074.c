/*
	Problem 74: Digit factorial chains

	The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:

	1! + 4! + 5! = 1 + 24 + 120 = 145
	Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are only three such loops that exist:
	169 → 363601 → 1454 → 169
	871 → 45361 → 871
	872 → 45362 → 872

	It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,

	69 → 363600 → 1454 → 169 → 363601 (→ 1454)
	78 → 45360 → 871 → 45361 (→ 871)
	540 → 145 (→ 145)

	Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number below one million is sixty terms.

	How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?
	1 dic. 2018
 */

#include "libEuler.h"
#define N 1000000

void P0074(void){
	time_t tInit=clock();
	long unsigned int factorials[10]={1}, sum=0, cont=1, finalCount=0, index=0;
	int len=0, reps[100], end=0;
	char strSum[100]={'\0'};
	for(int i=1;i<10;i++){
		factorials[i]=i;
		for(int j=i-1;j>1;j--) factorials[i]*=j;
	}
	for(long unsigned int i=0;i<N;i++){
		sum=i;
		end=0;
		cont=1;
		index=0;
		for(int i=0;i<100;i++) reps[i]=0;
		while(end!=1){
			for(int i=0;i<100;i++) strSum[i]='\0';
			sprintf(strSum,"%lu",sum);
			len=strlen(strSum);
			sum=0;
			for(int j=0;j<len;j++) sum+=factorials[strSum[j]-'0'];
			for(int k=0;reps[k]!=0;k++){
				if(reps[k]==sum){
					end=1;
					break;
				}
			}
			if(end!=1){
				reps[index]=sum;
				index++;
				cont++;
			}
			if(cont>61) break;
		}
		if(cont==60) finalCount++;
	}
	time_t tEnd=clock();
	printf("Problem 74 - Result: %lu. Elapsed Time: %.6f\n", finalCount,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
