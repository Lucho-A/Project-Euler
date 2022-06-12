/*
	Double-base palindromes
	Problem 36

	The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

	Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

	(Please note that the palindromic number, in either base, may not include leading zeros.)

	13 oct. 2018
 */

#include "../../Src/Headers/libEuler.h"
#define N 1000000

void P0036(void){
	time_t tInit=clock();
	llu sum=0;
	char numDec[50]={'\0'};
	char numBinary[50]={'\0'};
	for(llu i=1;i<N;i+=2){
		sprintf(numDec,"%Ld",i);
		if(is_palindrome(numDec)){
			dec_to_binary(numDec, numBinary);
			if(is_palindrome(numBinary)) sum+=i;
		}
	}
	time_t tEnd=clock();
	printf("Problem 36 - Result: %Ld. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
