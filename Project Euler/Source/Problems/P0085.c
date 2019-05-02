/*
 	Counting rectangles
	Problem 85

	27 abr. 2019
	Result: 2772 (1999998).
 */

#include "libEuler.h"

#define N 2000000
#define PRECISION 0.99999

void P0085(void){
	time_t tInit=clock();
	unsigned int count=0, area=0, y=0, x=0, next=0;
	double precition=0.0;
	for(y=1;;y++){
		next=0;
		for(x=1;next!=1;x++){
			count=0;
			for(int y0=1;y0<=y;y0++){
				for(int x0=1;x0<=x;x0++){
					count+=y0*x0;
				}
				if(count>N){
					next=1;
					break;
				}
			}
			precition=(double)count/N;
			if(precition<=1 && precition>PRECISION){
				area=y*x;
				time_t tEnd=clock();
				printf("Result: %u u^2 (%u, %u) (#%d). Elapsed time: %.6f",area,x,y,count,(double)(tEnd-tInit)/ CLOCKS_PER_SEC);
				return;
			}
		}
	}
}

