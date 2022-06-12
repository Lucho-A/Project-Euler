/*
	27 sep. 2018
 */

#include "../../Src/Headers/libEuler.h"

/*

void swap(char *x, char *y){
    char temp;
    temp = *x;
 *x = *y;
 *y = temp;
}

void permute(char *a, int l, int r){
	int i;
	if (l == r){
	  //use of the function(a);
	}else{
		for (i = l; i <= r; i++){
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i));
		}
	}
}
*/

double counting_combination(double n, double r){
	double i=0.0,result=1.0;
	for(i=1.0;i<=r;i++){
		result*=n/i;
		n--;
	}
	return result;
}

bool is_permutation_of(lu n1, lu n2){
	char strN1[10]="", strN2[10]="";
	sprintf(strN1, "%lu", n1);
	sprintf(strN2, "%lu", n2);
	int len1=strlen(strN1), len2=strlen(strN2);
	bool found=FALSE;
	if(len1!=len2) return FALSE;
	for(int i=0;i<len1;i++){
		found=FALSE;
		for(int j=0;j<len1;j++){
			if(strN1[i]==strN2[j]){
				found=TRUE;
				break;
			}
		}
		if(found==FALSE) return FALSE;
	}
	return TRUE;
}

ld combinatory(llu m, llu n){
	long double num=1.0,deno=1.0, i=0.0;
	for(i=m;i>n;i--) num*=i;
	for(i=m-n;i>1;i--) deno*=i;
	return (num/deno);
}

/*
void lexi_permutate(char *s, llu n){
	llu k=0,l=0, count=1, len=strlen(s);
	char sAux=' ';
	for(int i=0;i<len-1;i++){
		for(int j=i;j<len;j++){
			if(s[i]>s[j]){
				sAux=s[i];
				s[i]=s[j];
				s[j]=sAux;
			}
		}
	}
	//while(count!=n){
	while(TRUE){
    	//printf("%s\n",s);
		k=-1;
		for(int i=0;i<len;i++) if(s[i]<s[i+1]) k=i;
		if(k==-1) break;
		for(l=len-1;l>=0;l--) if(s[k]<s[l]) break;
		sAux=s[k];
		s[k]=s[l];
		s[l]=sAux;
		for(int i=k+1;i<len-1;i++){
			for(int j=i+1;j<len;j++){
				if(s[i]>s[j]){
					sAux=s[i];
					s[i]=s[j];
					s[j]=sAux;
				}
			}
		}
		count++;
	}
	return;
}
 */
