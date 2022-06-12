/*
Special Pythagorean triplet
Problem 9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include "libEuler.h"

#define S 1000

llu P0009(void){
    llu a=0,b=0,c=0,s=S,s2=0, mlimit=0,sm=0,d=0,m=0,k=0,n=0;
    s2=s/2;
    mlimit=ceil(sqrt(s2))-1;
    for(m=2;m<mlimit;m++){
    	if(s2%m==0){
    		sm=s2/m;
    		while(sm%2==0) sm/=2;
    		(m%2==1)?(k=m+2):(k=m+1);
    		while(k<2*m && k<=sm){
    			if(sm%k==0 && gcd(k,m)==1){
    				d=s2/(k*m);
    				n=k-m;
    				a=d*(m*m-n*n);
    				b=2*d*m*n;
    				c=d*(m*m+n*n);
    				return a*b*c;
    			}
    			k+=2;
    		}
    	}
    }
    return -1;
}

