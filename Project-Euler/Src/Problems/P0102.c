/*
	Triangle containment

	Problem 102

	L
	1 mar. 2020-11:32:54
 */

#include "../../Src/Headers/libEuler.h"
#define EQ_RECTA(x,x1,x2,y1,y2) (((y2-y1)/(x2-x1))*(x-x1)+y1)
//#define EQ_X(x1,x2,y1,y2) ((((y2-y1)*x1)/(x2-x1))-y1)*((x2-x1)/(y2-y1))
#define EQ_X(x1,x2,y1,y2) (((y-y1)+(((y2-y1)/(x2-x1))*x1))*((x2-x1)/(y2-y1)))
void P0102(void){
	time_t tInit=clock();
	int count=0;
	double x=0.0,termA=0.0,termB=0.0;
	FILE *f=fopen("Resources/P0102/p102_triangles.txt","r");
	if(!f) EXIT_FAILURE;
	int x1=0, y1=0,x2=0, y2=0,x3=0, y3=0;
	while (fscanf(f,"%d,%d,%d,%d,%d,%d",&x1,&y1,&x2,&y2,&x3,&y3)==6) {
		//L1
		termA=(double)((y2-y1)/(x2-x1));
		termB=(double)((y2-y1)/(x2-x1))*x1;
		x=(termB-y1)/termA;
		if(x>=0 && x<=1000) count++;
		//printf("(%d,%d)(%d,%d)=%.f - ",x1,y1,x2,y2,x);
		//L2
		termA=(double)((y3-y2)/(x3-x2));
		termB=(double)((y3-y2)/(x3-x2))*x2;
		x=(termB-y2)/termA;
		if(x>=0 && x<=1000) count++;
		//printf("(%d,%d)(%d,%d)=%.f - ",x2,y2,x3,y3,x);
		//L3
		termA=(double)((y1-y3)/(x1-x3));
		termB=(double)((y1-y3)/(x1-x3))*x3;
		x=(termB-y3)/termA;
		if(x>=0 && x<=1000) count++;
		//printf("(%d,%d)(%d,%d)=%.f\n",x3,y3,x1,y1,x);
		if(count==1) printf("(%d,%d)(%d,%d)(%d,%d)!\n",x1,y1,x2,y2,x3,y3);
		count=0;
		//if(count==10) return;
	}
	time_t tEnd=clock();
	printf("Problem P0102 - Result: %f. Elapsed Time: %.6f\n", 0.0,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
