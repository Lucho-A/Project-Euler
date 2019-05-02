/*
 * prime.c
 *
 *  Created on: 24/04/2018
 *      Author: lucho
 */

#include "libEuler.h"

bool isPrime(llu number){
	if(number==1) return FALSE;
	if(number<4) return TRUE;
	if(number%2==0) return FALSE;
	if(number<9) return TRUE;
	if(number%3==0) return FALSE;
	llu r;
	r=floor(sqrt(number));
	llu f=5;
	while(f<=r){
		if(number%f==0) return FALSE;
		if(number%(f+2)==0) return FALSE;
		f=f+6;
	}
	return TRUE;
}

void generate_vector_of_primes(Vector *v, llu n){
	llu sievebound=(n-1)/2;
	llu i=0,j=0;
	llu crosslimit=(sqrt(n)-1)/2;
	llu *vAux=malloc(sizeof(llu)*sievebound);
	for(i=0;i<sievebound;i++) vAux[i]=FALSE;
	for(i=1;i<crosslimit;i++){
		if(vAux[i]==FALSE){
			for(j=2*i*(i+1);j<sievebound;j+=2*i+1) vAux[j]=TRUE;
		}
	}
	vAdd(v,2,-1);
	for(llu i=1;i<sievebound;i++){
		if(vAux[i]==FALSE) vAdd(v,2*i+1,-1);
	}
	free(vAux);
	return;
}
