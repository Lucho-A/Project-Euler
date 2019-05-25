/*
 * prime.c
 *
 *  Created on: 24/04/2018
 *      Author: lucho
 */

#include "libEuler.h"

bool is_prime(llu number){
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

llu generate_vector_of_primes(lu **v, llu n){
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
	*v=NULL;
	llu cont=1;
	*v=malloc(sizeof(lu)*sievebound);
	(*v)[0]=2;
	for(llu i=1;i<sievebound;i++){
		if(vAux[i]==FALSE) {
			(*v)[cont]=2*i+1;
			cont++;
		}
	}
	free(vAux);
	return cont;
}

bool is_circular_prime(lu n){
    char strPrime[10], strPrimeAux[10]="";
	sprintf(strPrime,"%lu",n);
	llu len=strlen(strPrime), cont=0, ind=1;
	do{
		for(int i=ind;i<len+ind;i++,cont++) strPrimeAux[cont]=strPrime[i%len]; //!!
		if(is_prime(strtol(strPrimeAux,NULL,10))==FALSE) return FALSE;
		ind++;
		cont=0;
	}while(strtol(strPrimeAux,NULL,10)!=n);
	return TRUE;
}
