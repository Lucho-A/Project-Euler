/*
	Triangle containment

	Problem 102

	L
	1 mar. 2020-11:32:54
*/

#include "libEuler.h"
#define EQ_RECTA(x,x1,x2,y1,y2) (((y2-y1)/(x2-x1))*(x-x1)+y1)
void P0102(void){
	time_t tInit=clock();
	int count=0;
	FILE *f=fopen("Resources/P0102/p102_triangles.txt","r");
	if(!f) EXIT_FAILURE;
	int x1=0, y1=0,x2=0, y2=0,x3=0, y3=0, x=0, y=0;
	while (fscanf(f,"%d,%d,%d,%d,%d,%d",&x1,&y1,&x2,&y2,&x3,&y3)==6) {
		if(((y1&&y2&&y3)<0 || (y1&&y2&&y3)>0)==FALSE){
			for(int x=-1*abs(x1);x<abs(x2);x++){
				y=EQ_RECTA(x,x1,x2,y1,y2);
				//if()
			}
		}
		//printf("(%d,%d)(%d,%d)(%d,%d)\n",x1,y1,x2,y2,x3,y3);
	}
	time_t tEnd=clock();
	printf("Problem P0102 - Result: %f. Elapsed Time: %.6f\n", 0.0,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
