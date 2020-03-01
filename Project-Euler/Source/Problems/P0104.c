/*
	Problem 104: Pandigital Fibonacci ends

	The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

    It turns out that F541, which contains 113 digits, is the first Fibonacci number for which the last nine digits are 1-9 pandigital (contain all the digits 1 to 9, but not necessarily
    in order).

    And F2749, which contains 575 digits, is the first Fibonacci number for which the first nine digits are 1-9 pandigital.

    Given that Fk is the first Fibonacci number for which the first nine digits AND the last nine digits are 1-9 pandigital, find k.

	6 dic. 2018
 */

#include "libEuler.h"
#define DIGITS 100000
char fibo[3][DIGITS];

int is_pandigital(char *n){
	int digits[10]={0};
	int i,ini=1;
	for(i=ini;i<10;i++){
		if(digits[n[i-1]-'0']>0 || n[i-1]-'0'==0) return FALSE;
		digits[n[i-1]-'0']++;
	}
	for (int i=0;i<10;i++) digits[i]=0;
	ini=strlen(n)-9;
	for(i=ini;i<strlen(n);i++){
		if(digits[n[i]-'0']>0 || n[i]-'0'==0) return FALSE;
		digits[n[i]-'0']++;
	}
	return TRUE;
}

int evaluate(){
	int ind=3;
	int len1=0, len2=0, carry=0, sum=0, cont=0;
	char rAux[DIGITS]={'\0'};
	while(TRUE){
		cont=0;
		carry=0;
		sum=0;
		len1=strlen(fibo[0]) - 1;
		len2=strlen(fibo[1]) - 1;
		while(len1>=0 || len2>=0){
			if(len1>=0 && len2>=0){
				sum=fibo[0][len1] - '0' + fibo[1][len2] - '0';
			}else{
				(len1>=0 && len2<0) ? (sum=fibo[0][len1]-'0'):(sum=fibo[1][len2]-'0');
			}
			fibo[2][cont]=((sum + carry)%10) + '0';
			(sum+carry > 9)?(carry=1):(carry=0);
			len1--;
			len2--;
			cont++;
		}
		if(carry==1){
			fibo[2][cont]=1 + '0';
			cont++;
		}
		fibo[2][cont]='\0';
		cont=0;
		strcpy(rAux,fibo[2]);
		for(int k=strlen(rAux)-1;k>=0;k--, cont++) fibo[2][cont]=rAux[k];
		fibo[2][cont]='\0';
		if(is_pandigital(fibo[2])==TRUE) return ind;
		strcpy(fibo[0],fibo[1]);
		strcpy(fibo[1],fibo[2]);
		strcpy(fibo[2],"");
		ind++;
	}
	return 0;
}

void P0104(void){
	time_t tInit=clock();
	int resp=0;
	strcpy(fibo[0],"1");
	strcpy(fibo[1],"1");
	strcpy(fibo[2],"");
	resp = evaluate();
	time_t tEnd=clock();
	printf("\nResult: %d \n. Elapsed time: %.6f\n", resp, (double) (tEnd - tInit)/CLOCKS_PER_SEC);
	return;
}
