/*

*/

#include "libEuler.h"

bool is_even(llu n){
	if(n%2==0) return TRUE;
	return FALSE;
}

llu fibonacci_by_Lucas(llu n){
	return floor((1/sqrtl(5))*(powl((1+sqrtl(5))/2,n)+0.5));
}

llu fibonacci_qDigits(llu n){
	long double o=(1+sqrtl(5))/2;
	return ceil(n*log10l(o)-((log10l(5)) / 2)); // Binet's formula
}

llu gcd(llu a, llu b){
	llu t=0;
	while(b){
		t=b;
		b=a%b;
		a=t;
	}
    return a;
}

llu triangle_number(llu pos){
	return (pos*(pos - 1))/2;
}

llu sum_of_divisors(llu n){
	llu sum=1, p=2, j=0;
	while(p*p<=n && n>1){
		if(n%p==0){
			j=p*p;
			n/=p;
			while(n%p==0){
				j*=p;
				n/=p;
			}
			sum*=(j-1);
			sum/=(p-1);
		}
		if(p==2){
			p=3;
		}else{
			p+=2;
		}
	}
	if(n>1) sum*=(n+1);
	return sum;
}

llu sum_of_proper_divisors(llu n){
	return sum_of_divisors(n)-n; //without itself at divisor
}
