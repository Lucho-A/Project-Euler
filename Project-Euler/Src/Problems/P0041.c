/*
	Pandigital prime
	Problem 41

	We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

	What is the largest n-digit pandigital prime that exists?

	A number is prime if it has no factors except one and itself.
	A number is divisible by 3 whether the sum of its digits is divisible 3.
	A number is pandigital if it uses the digits from 1 to n exactly once.
	The sum of all 9 digit pandigital numbers is 1+2+3+4+5+6+7+8+9= 45 which is divisible by 3. Hence no 9 digit pandigital number is prime.
	The sum of all 8 digit pandigital numbers is 1+2+3+4+5+6+7+8=36 which is divisible by 3. Hence no 8 digit pandigital number is prime.
	The sum of all 7 pandigital numbers is 28 which is not divisible by 3. so a 7 digit pandigital number can be prime or not.
	Since we are looking for the largest prime pandigital number we can begin from 7654321 which is the largest 7 digit pandigital number.

	23 dic. 2018
 */

#include "../../Src/Headers/libEuler.h"

int isPandigital(long unsigned int n){
	char strN[11];
	sprintf(strN, "%lu", n);
	int len=strlen(strN);
	for(int i=0;i<len-1;i++){
		for(int j=i+1;j<len;j++){
			if(strN[i]-'0'==strN[j]-'0' || strN[i]-'0'>len || strN[j]-'0'>len || strN[i]-'0'==0 || strN[j]-'0'==0) return FALSE;
		}
	}
	return TRUE;
}

void P0041(void){
	time_t tInit=clock();
	for(llu i=7654321;;i-=2){
		if(isPandigital(i)==TRUE && is_prime(i)==TRUE){
			time_t tEnd=clock();
			printf("Problem 41 - Result: %llu. Elapsed Time: %.6f\n", i,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
			return;
		}
	}
	exit(1);
}
