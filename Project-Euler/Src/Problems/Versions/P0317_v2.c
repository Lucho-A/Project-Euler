/*
Firecracker
Problem 317

A firecracker explodes at a height of 100 m above level ground.
It breaks into a large number of very small fragments, which move in every
direction; all of them have the same initial velocity of 20 m/s.

We assume that the fragments move without air resistance, in a uniform gravitational
field with g=9.81 m/s2.

Find the volume (in m3) of the region through which the fragments move before
reaching the ground. Give your answer rounded to four decimal places.

19 abr. 2019/14:07:09
*/

#include "../../../Src/Headers/libEuler.h"

#define V 20.0
#define G 9.81
#define H 100.0
#define PRECITION 0.0001
#define STEP 0.0001
#define EQ1 (H+((V*V)/(2*G)))
#define EQ2 (-G/(2*V*V))

void P0137_v2(void){
    time_t tInit=clock();
    double y=0.1, volCilindre=0.0, vol=0.0, x=0.0, yAnt=0.0, dy=0.0;
    double step=STEP;
    for(x=0.0; y>0.0;x+=step){
    	//printf("Last y: %.20LF, dy: %.20LF\n",y,dy);
    	//getchar();
        y=(EQ2*(x*x))+EQ1;
        dy=yAnt-y;
        volCilindre=PI*x*x*dy;
        vol+=volCilindre;
        yAnt=y;
        (dy>PRECITION)?(step/=2):(step*=2);
    }
    time_t tEnd=clock();
    printf("Result: %f. Elapsed Time: %.6f\n", vol,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
