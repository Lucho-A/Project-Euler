/*
 * P0016.c
 *
 * Created on: 11 ago. 2018
*/

#include "libEuler.h"

void P0016(void){
    time_t tInit=clock();
    double d=powl(2,1000);
    char strR[500]={'\0'};
    int sum=0;
    sprintf(strR,"%f",d);
    for(int i=0;strR[i]!='.';i++) sum+=strR[i]-'0';
    time_t tEnd=clock();
    printf("Problem 16 - Result: %d. Elapsed Time: %.6f\n",sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
