/*

	19 ago. 2019
 */

#include "libEuler.h"
#define N 1000001

void P0058(void){
	time_t tInit=clock();
	int matrix[N][N]={{0}};
	int x=N/2, y=N/2,cont=1, dir=1, side=1;
	double ratio=0;
	matrix[y][x]=cont;
	x++;
	cont++;
	matrix[y][x]=cont;
	cont++;
	while(x>=0 && x<N && y>=0 && y<N){
		if(dir==1){
			if (matrix[y-1][x]==0){
				y--;
				matrix[y][x]=cont;
				dir=2;
			}else{
				x++;
				matrix[y][x]=cont;
			}
			cont++;
		}
		if(dir==2){
			if (matrix[y][x-1]==0){
				x--;
				matrix[y][x]=cont;
				dir=3;
			}else{
				y--;
				matrix[y][x]=cont;
			}
			cont++;
		}
		if(dir==3){
			if (matrix[y+1][x]==0){
				y++;
				matrix[y][x]=cont;
				dir=4;
			}else{
				x--;
				matrix[y][x]=cont;
			}
			cont++;
		}
		if(dir==4){
			if (matrix[y][x+1]==0){
				x++;
				matrix[y][x]=cont;
				dir=1;
			}else{
				y++;
				matrix[y][x]=cont;
			}
			cont++;
		}
	}
	double contPrimes=0.0;
	int ini=N/2;
	if(is_prime(matrix[ini][ini])) contPrimes++;
	for(int y=ini+1,d=ini-1;y<N;y++,d--){
		side+=2;
		if(is_prime(matrix[y][y])) contPrimes++;
		if(is_prime(matrix[d][d])) contPrimes++;
		if(is_prime(matrix[y][d])) contPrimes++;
		if(is_prime(matrix[d][y])) contPrimes++;
		ratio = ((contPrimes/(double)(side*2.0-1)) * 100);
		//printf("%.4lf\n", ratio);
		if(ratio<10.0){
			time_t tEnd=clock();
			printf("Problem 58 - Result: %d (%.4lf). Elapsed Time: %.6f\n",side, ratio,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
			return;
		}
	}
}

