/*
	strings.c
	L.
	1 sep. 2019-14:55:36
 */

#include "libEuler.h"

ld len(char *v){
	for(ld i=0;;i++) if(v[i]=='\0') return i;
	return 0;
}
