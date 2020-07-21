/*
 * arithmeticOperations.c
 *
 * Created on: 12 ago. 2018
 * Author: lucho
 */

#include "libEuler.h"
#define LIMIT 10000

void sum_big_numbers(char *num1, char *num2, char *result){
	long int carry=0, sum=0, i=0, len1= len(num1)-1, len2=len(num2)-1, n=0;
	if(num1[len1]=='\n')len1--;
	if(num2[len2]=='\n')len2--;
	char *aux=malloc(sizeof(char)*MAX_DIGIT);
	for(lu in=0;in<MAX_DIGIT;in++) aux[in]='\0';
	while(len1>=0 || len2>=0){
		if(len1>=0 && len2>=0){
			n=num1[len1]-'0' + num2[len2]-'0';
		}else{
			len1<0 ? (n=num2[len2]-'0') : (n=num1[len1]-'0');
		}
		sum=n+carry;
		carry=0;
		aux[i]=sum%10+'0';
		if(sum>9) carry=1;
		i++;
		len1--;
		len2--;
	}
	if(carry==1) aux[i]='1';
	lu cont=0;
	for(int i=strlen(aux)-1; i>=0;i--){
		result[cont]=aux[i];
		cont++;
	}
	free(aux);
}

void multip_big_numbers(char *n1, char *n2, char *result){
	//char mN[1000][1000]={{"\0"}};
	ld lenN1=len(n1), lenN2=len(n2);
	ld carry=0, ind=0, mult=0, i=0, j=0, cont=0, esp=0;
	char **mN=(char **)malloc(lenN1 * lenN2 * sizeof(char*));
	for(int i=0; i<lenN1 * lenN2;i++) mN[i] = (char *)malloc(lenN1 * lenN2 * sizeof(char));
	for(int i=0;i<lenN1 * lenN2;i++){
		for(int j=0;j<lenN1 * lenN2;j++)mN[i][j]='\0';
		//mN[i][0]='\0';
	}
	for(i=lenN2-1;i>=0;i--){
		for(int i=0;i<esp;i++) mN[ind][i]='0';
		cont=esp;
		for(j=lenN1-1;j>=0;j--){
			mult=((n2[i])-'0') * ((n1[j])-'0') + carry;
			carry=0;
			if(mult<10){
				mN[ind][cont]=mult+'0';
			}else{
				mN[ind][cont] = (mult%10)+'0';
				carry=floor(mult/10);
			}
			cont++;
		}
		if(carry!=0){
			if(carry<10){
				mN[ind][cont]=carry +'0';
			}else{
				mN[ind][cont]=(carry%10) +'0';
				mN[ind][cont+1]=floor(carry/10) +'0';
			}
			carry=0;
		}
		esp++;
		ind++;
	}
	//for(lu i=0;i<len(result);i++) result[i]='\0';
	strcpy(result,"0");
	char strN1[MAX_DIGIT]={'\0'};
	for(int i=0;mN[i][0]!='\0';i++){
		cont=0;
		for(int j=len(mN[i])-1;j>=0;j--, cont++) strN1[cont]=mN[i][j];
		mN[i][cont]='\0';
		sum_big_numbers(strN1,result,result);
	}
	return;
}

void potencia(char *base, char *exp, char *result){
	for(ld i=0;i<MAX_DIGIT;i++) result[i]='\0';
	strcpy(result, base);
	for(ld i=1;i<strtol(exp,NULL,10);i++) multip_big_numbers(result,base,result);
}

lf factoriall(int n){
	lf r=1;
	for(int i=n;i>1;i--) r*=i;
	return r;
}

void factorial(int num, char *result){
	char strNum[200]={'\0'};
	sprintf(result,"%d",num);
	num--;
	char aux[LIMIT]={'\0'};
	do{
		strcpy(aux,result);
		for(int i=num;i>1;i--){
			sprintf(strNum,"%d",i);
			sum_big_numbers(result,aux,result);
		}
		num--;
	}while(num!=1);
}
