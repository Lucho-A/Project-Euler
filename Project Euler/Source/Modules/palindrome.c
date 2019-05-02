/*
 * palindrome.c
 *
 *  Created on: 24/04/2018
 *      Author: lucho
 */
#include "libEuler.h"

bool is_palindrome(char *c){
    int len =0, i, j;
    len=strlen(c);
    for(i=0, j=len-1 ; i<len/2 ; i++, j--){
        if(c[i]!=c[j]) return FALSE;
    }
    return TRUE;
}
