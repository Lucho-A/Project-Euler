/*
	Problem 27

	Euler discovered the remarkable quadratic formula: n^2+n+41

	It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39.
	However, when n=40,40^2+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,41^2+41+41
	is clearly divisible by 41.

	The incredible formula n^2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79.
	The product of the coefficients, −79 and 1601, is −126479.

	Considering quadratics of the form: n^2+an+b , where |a|<1000 and |b|≤1000

	where |n| is the modulus/absolute value of n (e.g. |11|=11 and |−4|=4)

	Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of
	primes for consecutive values of n, starting with n=0.

	1 dic. 2018
 */

#include "libEuler.h"

void P0027(void){
	time_t tInit=clock();
	int consecutivePrimes=0, maxConsecutivePrimes=0, coefProduct=0, maxCoefProduct=0;
	int a=0, b=0, n=0, flag = FALSE, result=0;
	for(a=-1000;a<1000;a++){
		for(b=-1001;b<1001;b++){
			flag=FALSE;
			coefProduct=a*b;
			consecutivePrimes=0;
			for(n = 0;flag==FALSE;n++){
				result=n*n+a*n+b;
				if(result>0){
					if(isPrime(result)){
						consecutivePrimes++;
					}else{
						if(consecutivePrimes>=maxConsecutivePrimes){
							maxCoefProduct=coefProduct;
							maxConsecutivePrimes=consecutivePrimes;
						}
						flag=TRUE;
					}
				}
			}
		}
	}
	time_t tEnd=clock();
	printf("Problem 27 - Result: %d. Elapsed Time: %.6f\n", maxCoefProduct,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
