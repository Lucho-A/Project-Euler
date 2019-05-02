/*
	Almost equilateral triangles
	Problem 94

	It is easily proved that no equilateral triangle exists with integral length sides and
	integral area. However, the almost equilateral triangle 5-5-6 has an area of 12 square
	units.

	We shall define an almost equilateral triangle to be a triangle for which two sides are
	equal and the third differs by no more than one unit.

	Find the sum of the perimeters of all almost equilateral triangles with integral side
	lengths and area and whose perimeters do not exceed one billion (1,000,000,000).

	25 sep. 2018
*/

#include "libEuler.h"
#define LIMIT 1000000001
//static inline long double area(long double c, long double b){return (b/4)*sqrtl(4*c*c-b*b);}
static inline long double area(long double c, long double b){return (b*sqrtl(c*c-(b*b/4)))/2;}
static inline long double perim(long double c, long double b){return 2*c+b;}

void P0094(void){
    time_t tInit=clock();
    long double sum=0, p=0, a=0, b=0;
    int flag=0;
    for(long double c=2;flag!=4;c++){
    	//flag=0;
    	b=c+1;
    	a=area(c,b);
    	if(a==floorl(a)){
    		p=perim(c,b);
    		printf("a=%Lf,c=%Lf, b=%Lf, p=%Lf\n",a,c,b,p);
    		//getchar();
    		if(p<LIMIT){
    			sum+=p;
    		}else{
    			flag++;
    		}
    	}
    	b=c-1;
    	a=area(c,b);
    	if(a==floorl(a)){
    		p=perim(c,b);
    		printf("a=%Lf,c=%Lf, b=%Lf, p=%Lf\n",a,c,b,p);
    		//getchar();
    		if(p<LIMIT){
    			sum+=p;
    		}else{
    			flag++;
    		}
    	}
    }
    time_t tEnd=clock();
    printf("Problem 94 - Result: %Lf. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
// 312530629458593024 no
// 312530630458593024 no
// 156265178176286656 no sin -1
// 312530630458602039 no
// 152273911417544 no
// 651119701692102 no
