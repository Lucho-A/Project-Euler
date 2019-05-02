/*
	Counting Sundays
	Problem 19

	You are given the following information, but you may prefer to do some
	research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century
    unless it is divisible by 400.

	How many Sundays fell on the first of the month during the twentieth century
	(1 Jan 1901 to 31 Dec 2000)?

	24 sep. 2018
 */

#include "libEuler.h"
#define N

void P0019(void){
	time_t tInit=clock();
	int result=0, year=1900, day=1, indDay=0, indMonth=0;
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	while(year<2001){
		month[1]=28;
		if((year%4==0 || year==2000) && year!=1900) month[1]=29;
		if(indDay==6 && day==1 && year>1900) result++;
		if(indDay==6) indDay=-1;
		if(day==month[indMonth]){
			day=0;
			if(indMonth==11) {
				indMonth=0;
				year++;
			}else{
				indMonth++;
			}
		}
		day++;
		indDay++;
	}
	time_t tEnd=clock();
	printf("Problem 19 - Result: %d. Elapsed Time: %.6f\n", result ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
