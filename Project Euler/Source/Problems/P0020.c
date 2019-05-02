
/*
Factorial digit sum
Problem 20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

12 ago. 2018
*/

#include "libEuler.h"
#define N 100

void P0020(void){
    time_t tInit=clock();
    int sum=0;
    char result[500]={'\0'};
    factorial(N,result);
    for(int i=0;i<strlen(result);i++) sum+=result[i]-'0';
    time_t tEnd=clock();
    printf("Problem 20 - Result: %d. Elapsed Time: %.6f\n",sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
