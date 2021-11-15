/*
	P0018.c

	L.
*/

#include "libEuler.h"

#define ROWS 80

void P0081(void){
	time_t tInit=clock();
	long int m[ROWS][ROWS]={{0}};
	FILE *fp=NULL;
	long int n=0;
	int contPos=0, row=0;
	if((fp=fopen("Resources/P0081/p081_matrix.txt", "r")) == NULL) exit(EXIT_FAILURE);
	while(fscanf(fp,"%ld,",&n)!=EOF){
		if(contPos==ROWS){
			contPos=0;
			row++;
		}
		m[row][contPos]=n;
		contPos++;
	}
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<ROWS;j++){
			if(i==0 && j==0) continue;
			if(i==0){
				m[i][j]+=m[i][j-1];
			}else{
				if(j==0){
					m[i][j]+=m[i-1][j];
				}else{
					(m[i][j-1]< m[i-1][j])?(m[i][j]+=m[i][j-1]):(m[i][j]+=m[i-1][j]);
				}
			}
		}
	}
	time_t tEnd=clock();
	printf("Problem 81 - Result: %ld. Elapsed Time: %.6f secs\n", m[ROWS-1][ROWS-1],(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}

