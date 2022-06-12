/*
	Goldbach's other conjecture
	Problem 46

	L
	11 may. 2019-20:38:38
 */

#include "../../Src/Headers/libEuler.h"

void P0046(void){
	time_t tInit=clock();
	int END=FALSE, found=FALSE, result=0, r=0;
	// sea R = a + 2 * b * b
	for(int n=1;END==FALSE;n++){
		// si es compuesto
		if(is_even(n)==FALSE && !is_prime(n)){
			// a�n no lo encontr�
			found=FALSE;
			// mientras no lo encuentre, y "a" sea menor a "n"
			for(int a=1;a<n && found==FALSE;a++){
				// si "a" es primo
				if(is_prime(a)){
					// mientras no lo encuentre y el doble del cuadrado no supere a "n"
					for(int b=1;2*b*b<n && found==FALSE;b++){
						// resuelvo la ecuaci�n
						result=a+2*b*b;
						// si lo encuentro, salgo del loop y contin�o la b�squeda
						if(result==n){
							found=TRUE;
							END=FALSE;
							// si no
						}else{
							r=n; // tengo el resultado
							END=TRUE; // finalizo
						}
					}
				}
			}
		}
	}
	time_t tEnd=clock();
	printf("Problem P0046 - Result: %d. Elapsed Time: %.6f\n", r,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
