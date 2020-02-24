/*
	Dice Game
	Problem 205
	L
	18 nov. 2019-21:01:31
 */

#include "libEuler.h"
#define INTENTOS 1000000000

int tiradaPeter(void){
	int sumaPeter=0;
	for(int i=0;i<9;i++) sumaPeter+=(rand() % 4)+1;
	return sumaPeter;
}

int tiradaColin(void){
	int sumaColin=0;
	for(int i=0;i<6;i++) sumaColin+=(rand() % 6)+1;
	return sumaColin;
}

void P0205(void){
	time_t tInit=clock();
	srand(time(NULL));
	double victoriasPeter=0;
	double victoriasColin=0;
	double empates=0;
	int resultPeter=0;
	int resultColin=0;
	for(double i= 0; i<INTENTOS;i++){
		resultPeter=tiradaPeter();
		resultColin=tiradaColin();
		if(resultPeter>resultColin){
			victoriasPeter++;
			continue;
		}
		if(resultPeter<resultColin){
			victoriasColin++;
			continue;
		}
		empates++;
	}
	printf("Probabilidad Peter: %.8lf\n", victoriasPeter/INTENTOS);
	printf("Probabilidad Colin: %.8lf\n", victoriasColin/INTENTOS);
	printf("Probabilidad Empate: %.8lf\n", empates/INTENTOS);
	time_t tEnd=clock();
	printf("Problem P0205 - Result: %f. Elapsed Time: %.6f\n", 0.0,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
