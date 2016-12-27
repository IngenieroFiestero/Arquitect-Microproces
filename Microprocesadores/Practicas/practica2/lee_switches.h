/*
 * lee_switches.h
 */

#ifndef LEE_SWITCHES_H_
#define LEE_SWITCHES_H_

#include<stdint.h>
#include<stdio.h>

#define SW1 0x2AA // Switch 1
#define SW2 0x1FF // Switch 2
#define SW12 0x199 // Switch 1+2
#define NoKey 0x3FF // No pulsacion
#define Error 0x4
#define rng 12 //
#define MAX_CNT 100
uint16_t lee_switches(void);


#endif /* LEE_SWITCHES_H_ */
