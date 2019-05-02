/*
	Longest Collatz sequence
	Problem 14

	The following iterative sequence is defined for the set of positive integers:

	n → n/2 (n is even)
	n → 3n + 1 (n is odd)

	Using the rule above and starting with 13, we generate the following sequence:
	13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
	Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers
	finish at 1.

	Which starting number, under one million, produces the longest chain?

	NOTE: Once the chain starts the terms are allowed to go above one million.

	9 jun. 2018/14:36:42
*/

#include "libEuler.h"

#define N 1000000

void P0014(void){
    time_t tInit=clock();
    long int maxChain=0;
    long int contChain=0;
    long int maxNumero=0;
    long int i=0;
    for(long int n=13;n<N;n++){
    	i=n;
    	contChain=0;
    	while(i!=1){
    		if(i%2==0){
    			i/=2;
    			contChain++;
    		}else{
    			i=3*i+1;
    			contChain++;
    		}
    	}
    	contChain++;
    	if(contChain>maxChain){
    		maxChain=contChain;
    		maxNumero=n;
    	}
    }
    time_t tEnd=clock();
    printf("Problem 14 - Result: %lu. Elapsed Time: %.6f\n", maxNumero,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
