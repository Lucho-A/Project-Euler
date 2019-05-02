/*
	Problem 6
	14 December 2001

	The sum of the squares of the first ten natural numbers is,
	12 + 22 + ... + 102 = 385

	The square of the sum of the first ten natural numbers is,
	(1 + 2 + ... + 10)2 = 552 = 3025

	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 385 = 2640.

	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include "libEuler.h"

#define N 100

void P0006(void){
    time_t tInit=clock();
    int i;
    llu sum_of_squares=0, sum=0, square_of_sum=0;
    for(i=1;i<=N;i++){
    	sum_of_squares += i*i;
    	sum+=+i;
    }
    square_of_sum = sum * sum;
    time_t tEnd=clock();
    printf("Problem 6 - Result: %llu. Elapsed Time: %.6f\n",square_of_sum-sum_of_squares ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
