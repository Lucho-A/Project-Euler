/*
	Ordered radicals
	Problem 124

	25 may. 2019
 */

#include "../../Src/Headers/libEuler.h"

#define N 100001
#define SEARCHED_N 10000

void rad(int indice, int *vRad, int *vE, lu *primes){
	int num=indice;
	vRad[indice]=1;
	if(is_prime(num)==TRUE){
		vRad[indice]=num;
		vE[indice]=indice;
		return;
	}
	for(int i=0; primes[i]<num;i++){
		if(num%primes[i]==0)vRad[indice]*=primes[i];
	}
	vE[indice]=indice;
	return;
}

void sort124(int *vRad, int *vE){
	int aux=0;
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(vRad[i]>vRad[j]){
				aux=vE[i];
				vE[i]=vE[j];
				vE[j]=aux;
				aux=vRad[i];
				vRad[i]=vRad[j];
				vRad[j]=aux;
			}
		}
	}
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(vRad[i]==vRad[j]){
				if(vE[i]>vE[j]){
					aux=vE[i];
					vE[i]=vE[j];
					vE[j]=aux;
					aux=vRad[i];
					vRad[i]=vRad[j];
					vRad[j]=aux;
				}
			}
		}
	}
	return;
}

void P0124(void){
	time_t tInit=clock();
	int vRad[N]={1}, vE[N]={0};
	lu *primes=NULL;
	printf("Generando primos...\n");
	generate_vector_of_primes(&primes, N+5);
	printf("Calculando rad(x)...\n");
	for(int i=1;i<N;i++) rad(i,vRad,vE, primes);
	printf("Ordenando...\n");
	sort124(vRad, vE);
	time_t tEnd=clock();
	printf("Problem 124 - Result: %d. Elapsed Time: %.6f\n", vE[SEARCHED_N],(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
