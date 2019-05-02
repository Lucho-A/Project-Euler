/*
	27 sep. 2018
*/

#include "libEuler.h"

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

long double combinatory(llu m, llu n){
	long double num=1.0,deno=1.0, i=0.0;
	for(i=m;i>n;i--) num*=i;
	for(i=m-n;i>1;i--) deno*=i;
	return (num/deno);
}

void lexi_permutate(char *s, llu n){
	llu k=0,l=0, count=1, len=strlen(s);
	char sAux=' ';
	while(count!=n){
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
