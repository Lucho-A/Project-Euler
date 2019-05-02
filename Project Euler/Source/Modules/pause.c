/*
 * pause.c
 *
 *  Created on: 24/04/2018
 *      Author: lucho
 */

#include "libEuler.h"

void pause(int sec){
        clock_t t=time(0)+sec;
        while(time(0)<t){};
        return;
}

