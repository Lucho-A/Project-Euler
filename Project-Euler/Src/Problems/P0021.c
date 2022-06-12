/*
Amicable numbers
Problem 21

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called
amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore
d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

30 abr. 2018/13:32:19
*/

#include "../../Src/Headers/libEuler.h"

#define N 10000

void P0021(void){
    time_t tInit=clock();
    llu sum=0, a=0, b=0;
    for(a=2;a<N;a++){
    	b=sum_of_proper_divisors(a);
    	if(b>a){
    		if(sum_of_proper_divisors(b)==a) sum+=a+b;
    	}
    }
    time_t tEnd=clock();
    printf("Problem 21 - Result: %llu. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
