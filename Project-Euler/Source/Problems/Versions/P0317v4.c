/*
	Firecracker

	Problem 317

	24 feb. 2020
 */

#include "libEuler.h"
#define PREC_ANG 10
#define PREC 0.1
#define V 20
#define G 9.81
#define EQ_ENV(x) (((V*V)/(2*G))-(G/(2*V*V))*(x*x))

void P0317v4(void){
	time_t tInit=clock();
	FILE *f=fopen("/home/lucho/git/Project-Euler/Project Euler/Resources/P0317/coord.cvs","w");
	FILE * gnuplotPipe = popen ("gnuplot-x11 -persistent", "w");
	long double vol=0.0, ang=90.0, Vx=0.0, Vx1=0.0, Vy=0.0, tMaxH=0.0;
	long double hMax=0.0, tTotal=0.0, r=0.0;
	long double hMaxAnt=0.0, tFF=0.0, rMax=0.0,Dh=0.0, cont=0.0;
	/*for(ang=75-PREC_ANG;;ang-=PREC_ANG,cont++){
		Vx=V*cos(ang*(PI/180));
		Vx1=V*cos((ang-PREC_ANG)*(PI/180));
		Vy=V*sin(ang*(PI/180));
		tMaxH=(-1*Vy)/(-1*G);
		hMax=100+Vy*tMaxH-0.5*G*tMaxH*tMaxH;
		tFF=sqrt(hMax*2/G);
		tTotal=tFF+tMaxH;
		fprintf(f,"S_%.0Lf\n",cont);
		for(long double t=PREC_T;t<=tTotal;t+=PREC_T){
			if(fabs(Vx*t-Vx1*t)<0.1) printf("X encontrado: %Lf\n",Vx);
			printf(": %Lf, %Lf\n",Vx*t,Vx1*t);
			//return;
			for(long double t1=0.0;t1<tTotal;t1+=PREC_T){
				//printf("(%Lf. %Lf)\n",Vx*t,Vx1*t1);
				if(Vx*t==Vx1*t1) printf("X encontrado: %Lf (%Lf,%Lf)\n",Vx,Vx*t,Vx1*t1);
			}
			r=Vx*tTotal;
			Dh=fabs(hMaxAnt-hMax);
			if(r<=rMax) break;
			//vol+=PI*r*r*Dh;
			fprintf(f,"%Lf %Lf\n",Vx*t,100+Vy*t-0.5*G*t*t);
		}
	if(r<=rMax) break;
	hMaxAnt=hMax;
	rMax=r;
	}*/
	fprintf(f,"S_%.0Lf\n",cont);
	long double y=0.0;
	for(long double x=0.1;y>=0.0;x+=PREC){
		y=EQ_ENV(x)+100;
		fprintf(f," %Lf, %Lf\n",x,y);
	}
	fprintf(f,"\n");
	fprintf(gnuplotPipe, "%s \n", "set terminal x11");
	fprintf(gnuplotPipe, "%s \n", "set style line 5 lt rgb 'red' lw 0.1 pt 0");
	fprintf(gnuplotPipe, "%s \n", "plot for [idx=0:1] '/home/lucho/git/Project-Euler/Project Euler/Resources/P0317/coord.cvs' i idx u 1:2 w linespoints ls 5 title 'PE317'");
	time_t tEnd=clock();
	printf("Problem 317v4 - Result: %Lf. Elapsed Time: %.6f\n",vol ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
