/*
	P0018.c
	20 jul. 2021
 */

#include "libEuler.h"
#define ROWS 5

void P0081v1(void){
	time_t tInit=clock();
	int m[ROWS][ROWS]={
			{131,673,234,103,18},
			{201,96,342,965,150},
			{630,803,746,422,111},
			{537,699,497,121,956},
			{805,732,524,37,331}
	};
	int row=0,col=0, sum=0;
	int r1[ROWS][ROWS]={{0}};
	int r2[ROWS][ROWS]={{0}};
	r1[0][0]=1;
	r2[0][0]=1;
	r1[ROWS-1][ROWS-1]=1;
	r2[ROWS-1][ROWS-1]=1;
	while(row<ROWS-1 || col<ROWS-1){
		r1[row][col]=1;
		if((row==ROWS-1 || (m[row][col+1] < m[row+1][col])) && col<ROWS-1){
			col++;
		}else{
			row++;
		}
	}
	printf("\n");
	row=ROWS-1;
	col=ROWS-1;
	while(row>0 || col>0){
		r2[row][col]=1;
		if((row==0 || (m[row][col-1] < m[row-1][col])) && col>0){
			col--;
		}else{
			row--;
		}
	}
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<ROWS;j++){
			if(!(r1[i][j]==0 && r2[i][j]==0)){
				if(r1[i][j]==r2[i][j]==1){
					sum+=m[i][j];
				}else{
					if((r1[i][j]<r2[i+1][j-1])){
						sum+=m[i][j];
					}else{
						sum+=m[i+1][j-1];
					}
					r1[i][j]=0;
					r2[i][j]=0;
					r1[i+1][j-1]=0;
					r2[i+1][j-1]=0;
					//printf("(%d,%d)(%d,%d)(%d) ",i,j,r1[i][j],r2[i][j],m[i][j]);
				}
				printf("\n");
				printf("%d",sum);
			}
		}
	}
	printf("\n");
	time_t tEnd=clock();
	printf("Problem 18 - Result: %d. Elapsed Time: %.6f secs\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}

