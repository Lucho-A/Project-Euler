/*
	Number spiral diagonals
	Problem 28

	Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed
	as follows:

	21 22 23 24 25
	20  7  8  9 10
	19  6  1  2 11
	18  5  4  3 12
	17 16 15 14 13

	It can be verified that the sum of the numbers on the diagonals is 101.

	What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
	22 sep. 2018
*/
#include "libEuler.h"
#define SIZE_SP 1001

void P0028(void){
    time_t tInit=clock();
    int r=1;
    for(int i=3;i<=SIZE_SP;i+=2) r+=4*i*i-6*(i-1);
    time_t tEnd=clock();
    printf("Problem 28 - Result: %d. Elapsed Time: %.6f\n", r,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
