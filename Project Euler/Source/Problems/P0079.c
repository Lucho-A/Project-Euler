/*
    Problem 79: Passcode derivation

    A common security method used for online banking is to ask the user for three random characters from a passcode.
    For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

    The text file, keylog.txt, contains fifty successful login attempts.

	Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.

	23 dic. 2018
 */

#include "libEuler.h"
#define ROWS 50
#define COLS 3

void P0079(void){
	time_t tInit=clock();
	FILE *f;
	int row=0, col=0;
	char c;
	int m[ROWS][COLS]={0};
	int n[10][10]={{-1}};
	int sumN[10]={0};
	int result[10]={0,1,2,3,4,5,6,7,8,9};
	if((f=fopen("Resources/P0079/p079_keylog.txt","r"))==NULL){
		printf("File error\n");
		exit(1);
	}
	while((c=getc(f)) != EOF){
		if(c!='\0' && c!='\n'){
			m[row][col]=c-'0';
			col++;
		}
		if(col==3){
			row++;
			col=0;
		}
	}
	fclose(f);
	int pos=0;
	for(int i=0; i<10;i++){
		for(row=0;row<ROWS;row++){
			pos=-1;
			for(col=0;col<COLS;col++){
				if(m[row][col]==i){
					pos=col;
				}else{
					if(pos!=-1)n[i][m[row][col]]=1;
				}
			}
		}
	}
	for(row=0;row<10;row++){
		for(col=0;col<10;col++) sumN[row]+= n[row][col];
	}
	int aux=0;
	for(int i=0;i<9;i++){
		for(int j=i+1;j<10;j++){
			if(sumN[i]<sumN[j]){
				aux=sumN[i];
				sumN[i]=sumN[j];
				sumN[j]=aux;
				aux=result[i];
				result[i]=result[j];
				result[j]=aux;
			}
		}
	}
	time_t tEnd=clock();
	printf("Problem 79 - Result: ");
	for(row=0;row<10;row++){
		if(sumN[row]!=0) printf("%d", result[row]);
	}
	printf("\n");
	printf("Elapsed Time: %.6f\n",(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
