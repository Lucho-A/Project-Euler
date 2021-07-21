/*
	P0018.c
	20 jul. 2021
*/

#include "libEuler.h"
#define NIVELES 4

void P0018(void){
    time_t tInit=clock();
    int matriz[NIVELES][NIVELES]={
    		{3,0,0,0},
    		{7,4,0,0},
    		{2,4,6,0},
    		{8,5,9,3}
    };
    int max=0, suma=0;

    int fila=0,col=0, colAux=0, cont=0;
    for(col=NIVELES-1;col>=0;col--){
    	suma=matriz[NIVELES-1][col];
    	colAux=col;
    	for(fila=NIVELES-2;fila>=0;fila--){
    		if(matriz[fila][colAux]!=0){
    			suma+=matriz[fila][colAux];
    			printf("%d\n",matriz[fila][colAux]);
    		}else{
    			suma+=matriz[fila][colAux-1];
    			printf("%d\n",matriz[fila][colAux-1]);
    			cont=-1;
    		}
			colAux=colAux-1;
    	}
    	if(suma>max) max=suma;
		printf("\n");
    }
    time_t tEnd=clock();
    printf("Problem 18 - Result: %d. Elapsed Time: %.6f\n", max,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}


