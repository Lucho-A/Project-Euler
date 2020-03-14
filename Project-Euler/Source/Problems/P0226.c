/*
	A Scoop of Blancmange

	Problem 226

	L
	14 mar. 2020-12:33:41
*/

#include "libEuler.h"
#define PREC 0.0001
#define LIMIT 30
#define BLANCMANGE_CURVE(x) (int(pow(2,n)))
#define CIRCLE(x,y) (sqrt((0.25*0.25)-((x-0.25)*(x-0.25)))+0.5)
void P0226(void){
	time_t tInit=clock();
	double x=0.0,y=0.0;
	for(x=0.0;x<=1.0;x+=PREC){
		y=0.0;
		for(long int n=0; n<LIMIT;n++){
			y+=(floor(pow(2,n)*x+0.5)/pow(2,n));
		}
		printf("%.5f %.5f\n",x,y);
	}
	time_t tEnd=clock();
	printf("Problem P0226 - Result: %f. Elapsed Time: %.6f\n", 0.0,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
