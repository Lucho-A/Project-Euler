/*
	Sub-string divisibility
	Problem 43

	The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order,
	but it also has a rather interesting sub-string divisibility property.

	Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

    d2d3d4=406 is divisible by 2
    d3d4d5=063 is divisible by 3
    d4d5d6=635 is divisible by 5
    d5d6d7=357 is divisible by 7
    d6d7d8=572 is divisible by 11
    d7d8d9=728 is divisible by 13
    d8d9d10=289 is divisible by 17

	Find the sum of all 0 to 9 pandigital numbers with this property.

	25 dic. 2018
*/

#include "libEuler.h"
lu sum=0;

int isDivisible(char *n){
	int aux=0;
	aux=(n[1]-'0')*100+(n[2]-'0')*10+(n[3]-'0');
	if(aux%2!=0) return FALSE;
	aux=(n[2]-'0')*100+(n[3]-'0')*10+(n[4]-'0');
	if(aux%3!=0) return FALSE;
	aux=(n[3]-'0')*100+(n[4]-'0')*10+(n[5]-'0');
	if(aux%5!=0) return FALSE;
	aux=(n[4]-'0')*100+(n[5]-'0')*10+(n[6]-'0');
	if(aux%7!=0) return FALSE;
	aux=(n[5]-'0')*100+(n[6]-'0')*10+(n[7]-'0');
	if(aux%11!=0) return FALSE;
	aux=(n[6]-'0')*100+(n[7]-'0')*10+(n[8]-'0');
	if(aux%13!=0) return FALSE;
	aux=(n[7]-'0')*100+(n[8]-'0')*10+(n[9]-'0');
	if(aux%17!=0) return FALSE;
	return TRUE;
}

void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r){
	int i;
	if (l == r){
		if(isDivisible(a)) sum+=strtoul(a,NULL,10);
	}else{
		for (i = l; i <= r; i++){
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i));
		}
	}
}


void P0043(void){
    time_t tInit=clock();
	char numbers[]="1234567890";
	permute(numbers,0,strlen(numbers)-1);
    time_t tEnd=clock();
    printf("Problem 43 - Result: %lu. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
