/*
	(prime-k) factorial
	Problem 381
	L
	20 ago. 2019-20:29:29
	Sources: https://en.wikipedia.org/wiki/Wilson%27s_theorem
 */

#include "libEuler.h"
#define P_MIN	5
//#define P_MAX	(pow(10,8))
#define P_MAX	100
#define K_MIN	1
#define K_MAX	5

double s(double p){
	double sum=0.0;
	//for(int k=K_MIN;k<=K_MAX;k++) sum+= factoriall(p-k);
	for(double k=K_MIN;k<=K_MAX;k++) sum+= fmod(fmod(k,p),p);
	//return fmod(sum,p);
	return sum;
}
void P0381(void){
	time_t tInit=clock();
	double sum=0.0;
	for(double p=P_MIN;p<P_MAX;p++){
		sum+=s(p);
		printf("Sum S(%.0f): %.0f\n",p,sum);
	}
	time_t tEnd=clock();
	printf("Problem 381 - Result: %.2f. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
