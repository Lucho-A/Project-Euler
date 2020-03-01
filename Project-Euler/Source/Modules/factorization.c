/*

 */

#include "libEuler.h"

llu maxFactor(llu num){
	int max=0;
	int end=FALSE;
	while(!end){
		end=TRUE;
		for(int i=2;i<=num;i++){
			if(((num % i) == 0)){
				num/=i;
				if(is_prime(i)==0) max=i;
				end=FALSE;
				break;
			}
		}
	}
	return max;
}

llu number_of_positive_divisor(llu n){
	llu *vPrimes=NULL;
	generate_vector_of_primes(&vPrimes,n/2);
	llu expCount=0, cantDiv=1;
	for(llu j=0;n!=1;){
		if(n%vPrimes[j]==0){
			expCount++;
			n/=vPrimes[j];
			if(n==1) cantDiv*=(expCount+1);
		}else{
			cantDiv*=(expCount+1);
			expCount=0;
			j++;
		}
	}
	free(vPrimes);
	return cantDiv;
}
