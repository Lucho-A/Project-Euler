/*
 * numberConversion.c
 *
 *  Created on: 24/04/2018
 *      Author: lucho
 */
#include "../../Src/Headers/libEuler.h"

void dec_to_binary(char *n, char *numBinary){
	llu luN=0;
	luN=strtoul(n,NULL,10);
	int i=0;
	while(luN>1){
		numBinary[i]=luN%2 + '0';
		luN=luN/2;
		i++;
	}
	numBinary[i]=luN + '0';
	return;
}
