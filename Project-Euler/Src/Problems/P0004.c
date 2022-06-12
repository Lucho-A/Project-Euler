/*
	A palindromic number reads the same both ways. The largest palindrome made from the product of
	two 2-digit numbers is 9009 = 91 * 99.

	Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include "libEuler.h"

#define N 1000

unsigned int P0004(void){
    char product[6];
    unsigned int max=0;
    for (unsigned int i=100;i<N;i++){
        for (unsigned int j=i+1;j<N;j++){
            sprintf(product,"%u", i*j);
            if(is_palindrome(product)){
                if(i*j>max) max=i*j;
            }
        }
    }
    return max;
}
