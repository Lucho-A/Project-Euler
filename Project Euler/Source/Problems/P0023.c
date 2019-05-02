
/*
	A perfect number is a number for which the sum of its proper divisors is exactly equal to
	the number.

	For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
	which means that 28 is a perfect number.

	A number whose proper divisors are less than the number is called deficient and a
	number whose proper divisors exceed the number is called abundant.

	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number
	that can be written as the sum of two abundant numbers is 24.

	By mathematical analysis, it can be shown that all integers greater than 28123 can be
	written as the sum of two abundant numbers.
	However, this upper limit cannot be reduced any further by analysis even though it is
	known that the greatest number that cannot
	be expressed as the sum of two abundant numbers is less than this limit.

	Find the sum of all the positive integers which cannot be written as the sum of two
	abundant numbers.

	26 sep. 2018
 */

#include "libEuler.h"
#define N 28123

void P0023(void){
	time_t tInit=clock();
	int abundant[N]={0}, abundantSum[N]={0}, sum=0;
	for(int i=12;i<N;i++) if(sum_of_proper_divisors(i)>i) abundant[i]=1;
	for(int i=12;i<N;i++){
		if(abundant[i]==1){
			sum=i;
			for(int j=i;j<N;j++){
				if (abundant[j]==1){
					sum+=j;
					if (sum<=N) abundantSum[sum]=1;
					sum=i;
				}
			}
		}
	}
	sum=0;
	for(int i=0;i<N;i++) if(abundantSum[i]==0) sum+=i;
	time_t tEnd=clock();
	printf("Problem 23 - Result: %d. Elapsed Time: %.6f\n",sum ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
