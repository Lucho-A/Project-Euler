/*
	Poker hands

	Problem 54

	L
	16 feb. 2020-22:17:01
 */

#include "libEuler.h"

void P0054(void){
	time_t tInit=clock();
	FILE *fp;
	char *line=NULL;
	int cont=0,hand=1;
	char j1[100]="";
	char j2[100]="";
	//char values[13]="23456789JQKA";
	fp = fopen("Resources/P0054/p054_poker.txt", "r");
	if (fp == NULL) exit(EXIT_FAILURE);
	char n[10]="";
	while (fscanf(fp, " %s", n)==1) {
		if(hand>5) return;
		if(cont==10){
			printf("Hand: %d\n", hand);
			printf("J1: %s - J2: %s\n", j1,j2);
			strcpy(j1,"");
			strcpy(j2,"");
			hand++;
			cont=0;
		}
		if(cont<5){
			strcat(j1,n);
			cont++;
		}else{
			if(cont<10){
				strcat(j2,n);
				cont++;
			}
		}
	}
	printf("Hand: %d\n", hand);
	printf("J1: %s - J2: %s\n", j1,j2);
	fclose(fp);
	if (line) free(line);
	time_t tEnd=clock();
	printf("Problem P0054.c - Result: %f. Elapsed Time: %.6f\n", 0.0,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}


