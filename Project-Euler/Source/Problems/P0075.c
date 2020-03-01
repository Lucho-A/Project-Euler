/*
Singular integer right triangles
Problem 75

It turns out that 12 cm is the smallest length of wire that can be bent to form
an integer sided right angle triangle in exactly one way, but there are
many more examples.

12 cm: (3,4,5)
24 cm: (6,8,10)
30 cm: (5,12,13)
36 cm: (9,12,15)
40 cm: (8,15,17)
48 cm: (12,16,20)

In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle
triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is
possible to form exactly three different integer sided right angle triangles.

120 cm: (30,40,50), (20,48,52), (24,45,51)

Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer
sided right angle triangle be formed?

30 abr. 2018/13:57:00
 */

#include "libEuler.h"
#define N 1500001

static inline llu f_sum(llu n,llu m,llu k){return k*(m*m-n*n)+k*(2*m*n)+k*(m*m+n*n);}

void P0075(void){
	time_t tInit=clock();
	llu count=0, sum=0;
	llu *vSums= malloc(N * sizeof(llu));
	for(int i=0;i<N;i++) vSums[i]=0;
	for (llu n=1;(((n+1)*(n+1)-n*n)+(2*(n+1)*n)+((n+1)*(n+1)+n*n))<N;n++){
		for (llu m=n+1;;m+=2){
			if(gcd(n,m)==1){
				sum=f_sum(n,m,1);
				if(sum>N) break;
				vSums[sum]++;
				for(llu k=2;;k++){
					sum=f_sum(n,m,k);
					if(sum>N) break;
					vSums[sum]++;
				}
			}
		}
	}
	for(int i=0;i<N;i++)if(vSums[i]==1) count++;
	time_t tEnd=clock();
	printf("Result: %llu. Elapsed Time: %.6f\n", count,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
