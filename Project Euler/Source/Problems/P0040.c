/*
	Champernowne's constant
	Problem 40

	An irrational decimal fraction is created by concatenating the positive integers:

	0.123456789101112131415161718192021...

	It can be seen that the 12th digit of the fractional part is 1.

	If dn represents the nth digit of the fractional part, find the value of the following expression.

	d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

	1 dic. 2018
*/

#include "libEuler.h"

void P0040(void){
    time_t tInit=clock();
	char *n=NULL;
	size_t len=0;
	llu result=0;
	FILE *f;
    f=fopen("Resources/P0040/P0040.tmp","w+");
    for(llu i=0;i<200000;i++) fprintf(f,"%llu",i);
    fclose(f);
    f=fopen("Resources/P0040/P0040.tmp","r");
    getline(&n, &len,f);
    fclose(f);
    result=(n[10]-'0') * (n[100]-'0') * (n[1000]-'0') * (n[10000]-'0') * (n[100000]-'0') * (n[1000000]-'0');
	time_t tEnd=clock();
    printf("Problem 40 - Result: %llu. Elapsed Time: %.6f\n",result ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
    return;
}
