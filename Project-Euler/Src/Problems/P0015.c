/*
	Lattice paths
	Problem 15

	Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

	How many such routes are there through a 20×20 grid?

	6 oct. 2018
 */

#include "../../Src/Headers/libEuler.h"

void P0015(void){
	time_t tInit=clock();
	long double r=combinatory(40,20);
	time_t tEnd=clock();
	printf("Problem 15 - Result: %.0LF Elapsed Time: %.6f\n", r,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
