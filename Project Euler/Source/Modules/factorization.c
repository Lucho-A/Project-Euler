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
