/*
 * SEmP_5515.h
 */

#ifndef SEMP_5515_H_
#define SEMP_5515_H_

#define CPU_IVPD *(volatile unsigned int *)0x0049
#define CPU_IVPH *(volatile unsigned int *)0x004A
//Registros de direccion de los GPIO 1,2
#define IODIR1 *(( ioport volatile unsigned int *) 0x1C06 )
#define IODIR2 *(( ioport volatile unsigned int *) 0x1C07 )
//Registros GPIO 1,2
#define IODATAOUT1 *(( ioport volatile unsigned int *) 0x1C0A )
#define IODATAOUT2 *(( ioport volatile unsigned int *) 0x1C0B )

#endif /* SEMP_5515_H_ */
