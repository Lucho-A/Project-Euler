/*
	P0018.c
	20 jul. 2021
 */

#include "libEuler.h"
#define ROWS 5

void P0081(void){
	time_t tInit=clock();
	int m[ROWS][ROWS]={
			{131,673,234,103,18},
			{201,96,342,965,150},
			{630,803,746,422,111},
			{537,699,497,121,956},
			{805,732,524,37,331}
	};
	int row=ROWS-2;
	int col=0;
	int level=3;
	while(level>-1){
		col=0;
		for(row=level;row>-1;row--,col++){
			if(m[row+1][col]<m[row][col+1]){
				m[row][col]+=m[row+1][col];
			}else{
				m[row][col]+=m[row][col+1];
			}
		}
		level--;
	}
	printf("%d ",m[0][0]);
	col=ROWS-1;
	level=2;
	while(level<ROWS){
		col=ROWS-1;
		for(row=level;row<ROWS;row++,col--){
			if(m[row-1][col]<m[row][col-1]){
				m[row][col]+=m[row-1][col];
			}else{
				m[row][col]+=m[row][col-1];
			}
		}
		level++;
	}
	printf("%d ",m[ROWS-1][ROWS-1]);
	time_t tEnd=clock();
	printf("Problem 18 - Result: %d. Elapsed Time: %.6f secs\n", m[0][0] + m[ROWS-1][ROWS-1],(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}

