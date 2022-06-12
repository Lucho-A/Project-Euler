/*
	Consecutive positive divisors
	Problem 51

	22 may. 2022
 */

#include "../../Src/Headers/libEuler.h"
#define N 200000

void P0051(void){
	time_t tInit=clock();
	llu *v=NULL;
	llu sievebound=(N-1)/2;
	llu i=0,j=0;
	llu crosslimit=(sqrt(N)-1)/2;
	llu *vAux=malloc(sizeof(llu)*sievebound);
	for(i=0;i<sievebound;i++) vAux[i]=FALSE;
	for(i=1;i<crosslimit;i++){
		if(vAux[i]==FALSE){
			for(j=2*i*(i+1);j<sievebound;j+=2*i+1) vAux[j]=TRUE;
		}
	}
	llu cont=1;
	v=malloc(sizeof(lu)*sievebound);
	(v)[0]=2;
	for(llu i=1;i<sievebound;i++){
		if(vAux[i]==FALSE) {
			(v)[cont]=2*i+1;
			cont++;
		}
	}

	//for(int i=0;i<cont;i++) printf("%Lu\n",v[i]);

	char strP[100000]="", strPD[100000][10]={""};
	int contD=0, contInx=0, contT=0;
	for(int i=0;i<cont;i++){
		contD=0;
		sprintf(strP,"%Lu",v[i]);
		for(int k=0;k<strlen(strP)-1;k++){
			for(int l=k+1;l<strlen(strP);l++){
				if(strP[k]==strP[l]){
					contD++;
				}
			}
		}
		if(contD>0){
			strcpy(strPD[contInx],strP);
			contInx++;
		}
	}
	for(int i=0;i<contInx-1;i++){
		contT=0;
		if(strlen(strPD[i])<4) continue;
		printf("\n\n%s\n",strPD[i]);
		for(int j=i+1;j<contInx;j++){
			if(strlen(strPD[i])!=strlen(strPD[j])) break;
			for(int k=0;k<strlen(strP)-1;k++){
				for(int l=k+1;l<strlen(strP);l++){
					if(strP[k]==strP[l]){
						//pos[indPos]=k;
					}
				}
			}

			if(strPD[i][0]==strPD[j][0]
									 && strPD[i][1]==strPD[j][1]
															  && strPD[i][strlen(strPD[i])-1]==strPD[j][strlen(strPD[j])-1]
																										&& strPD[i][2]==strPD[i][3]
																																 && strPD[j][2]==strPD[j][3]){
				printf("%s\n",strPD[j]);
				contT++;
			}
		}
		if(contT>7){
			printf("\n\n\nVamoooo: %s\n",strPD[i]);
			exit(0);
		}
	}
	time_t tEnd=clock();
	printf("Problem 51 - Result: %Lu. Elapsed Time: %.6f\n",cont ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
