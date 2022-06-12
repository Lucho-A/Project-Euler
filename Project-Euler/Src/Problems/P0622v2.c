/*
	Riffle Shuffles
	Problem 622

	L.

	12 nov. 2021
*/

#include "../../Src/Headers/libEuler.h"

#define LIMIT 150000 //400002, 1064626, 1756798 (30K), 3398090 (50K), 5131998 (70K), 8232188 (100K), 5625018 (100K->150K)
#define SN 60

void P0622v2(void){
	time_t tInit=clock();
	int end=FALSE;
	long int aux=0, cont=1, n=100000, sum=0,nAnt=1;
	long int *halves1 = malloc(sizeof(long int)*(LIMIT*2));
	long int *halves2 = malloc(sizeof(long int)*(LIMIT*2));
	while(n<LIMIT){
		for(int i=0;i<n*2-1;i+=2, aux++) halves1[i]=aux;
		while(end==FALSE){
			aux=n;
			for(int i=1;i<n*2;i+=2,aux+=2) halves1[i]=halves1[aux];
			end=TRUE;
			for(int i=1;i<n;i++){
				if(halves1[i]!=halves1[i-1]+1){
					end=FALSE;
					cont++;
					break;
				}
			}
			if(cont>SN) break;
			for(int i=0;i<n;i++) halves2[i]=halves1[i];
			aux=1;
			for(int i=1;i<n*2;i++){
				if(i%2!=0){
					(halves1[i]=0);
				}else{
					halves1[i]=halves2[aux];
					aux++;
				}
			}
		}
		if(cont==SN){
			printf("n: %ld (%.3f)\n",n, (double) n/nAnt);
			nAnt=n;
			sum+=n;
		}
		n+=2;
		cont=1;
		end=FALSE;
	}
	time_t tEnd=clock();
	printf("Problem 622 - Result: %ld. Elapsed Time: %.6f\n",sum ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
