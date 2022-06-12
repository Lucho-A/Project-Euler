/*
	Firecracker

	Problem 317

	24 feb. 2020
*/

#include "../../Src/Headers/libEuler.h"
#define PREC 0.0001
#define Vo 20.0
#define G 9.81
#define Ho 100
#define EQ_ENV(x) (((Vo*Vo)/(2.0*G))-(G/(2.0*Vo*Vo))*(x*x))

void P0317(void){
	time_t tInit=clock();
	long double x=0.0, y=1.0, vol=0.0;
	for(x=0.0;y>=0.0;x+=PREC){
		y=Ho+EQ_ENV(x);
		vol+=(x*y*PREC);
	}
	vol*=(2*PI);
	time_t tEnd=clock();
	printf("Problem 317 - Result: %.20Lg. Elapsed Time: %.6f\n",vol ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	//Problem 317 - Result: 1856532.845528. Elapsed Time: 1327.568204
	return;
}
