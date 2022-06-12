/*
	Project Euler (https://projecteuler.net/)
*/

#include "libEuler.h"
#define NS_PER_SECOND 1000000000.0

int main(void){
	struct timespec tInit, tEnd;
	clock_gettime(CLOCK_REALTIME,&tInit);
    /*
    P0001();
	P0002();
	P0003();
	P0004();
	P0005();
	P0006();
	P0007();
	P0008();
	P0009();
	P0010();
	P0011();
	P0012();
	P0013();
	P0014();
	P0015();
	P0016();
	P0018();
	P0019();
	P0020();
	P0021();
	P0022();
	P0023();
	P0024();
	P0025();
	P0026();
	P0027();
	P0028();
	P0029();
	P0030();
	P0032();
	P0034();
	P0035();
	P0036();
	P0037();
	P0038();
	P0039();
	P0040();
	P0041();
	P0042();
	P0043();
	P0044();
	P0045();
	P0046();
	P0049();
	P0050();
	*/
	//TODO P0051();
	/*
	P0053();
	P0057();
	P0054();
	P0056();
	P0058();
	*/
	//P0065();
	//P0067();
	//TODO P0070();
	//P0074();
	//P0075();
	//P0079();
	//P0081();
	//P0085();
	//TODO P0094();
	//P0097();
	//P0099();
	//TODO P0102();
	//P0104();
	//P0120();
	//TODO P0123();
	//P0124();
	//P0145();
	//TODO P0179();
	//TODO P0185();
	//P0226();
	//P0317();
	//P0179();
	//TODO P0205v2();
	//P0381();
	//TODO P0622v2();
	//TODO P0686();
	clock_gettime(CLOCK_REALTIME,&tEnd);
	printf("\n\nElapsed Time: %.3lf secs.\n\n", (double) (tEnd.tv_sec-tInit.tv_sec)+(tEnd.tv_nsec-tInit.tv_nsec)/NS_PER_SECOND);
	return EXIT_SUCCESS;
}
