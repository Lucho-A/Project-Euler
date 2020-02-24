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
	strcpy(result,n1);
	for(long int i=1;i<strtol(n2,NULL,10);i++) sum_big_numbers(result,n1,result);
}

void potencia(char *base, char *exp, char *result){
	char *multi=malloc(sizeof(char)*MAX_DIGIT);
	for(lu i=0;i<MAX_DIGIT;i++) result[i]='\0';
	strcpy(multi, base);
	strcpy(result, base);
	for(int i=1;i<strtol(exp,NULL,10);i++){
		multip_big_numbers(result,base,multi);
		strcpy(result,multi);
	}
	free(multi);
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
