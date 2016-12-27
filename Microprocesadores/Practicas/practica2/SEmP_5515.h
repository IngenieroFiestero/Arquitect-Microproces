/*
 * SEmP_5515.h
 */
#ifndef SEMP_5515_H_
#define SEMP_5515_H_

#define CPU_IVPD *(volatile unsigned int *) 0x0049
#define CPU_IVPH *(volatile unsigned int *) 0x004A

#define IODIR1 *(( ioport volatile unsigned int *) 0x1C06)
#define IODIR2 *(( ioport volatile unsigned int *) 0x1C07)

#define IODATAOUT1 *(( ioport volatile unsigned int *) 0x1C0A)
#define IODATAOUT2 *(( ioport volatile unsigned int *) 0x1C0B)

#define SARCLKCTRL *(( ioport volatile unsigned int *) 0x7016)
#define SARPINCTRL *(( ioport volatile unsigned int *) 0x7018)
#define SARGPOCTRL *(( ioport volatile unsigned int *) 0x701A)

#define SARCTRL *(( ioport volatile unsigned int *) 0x7012)
#define SARDATA *(( ioport volatile unsigned int *) 0x7014)

#define TIM0PRD1 *(( ioport volatile unsigned int *) 0x1812)
#define TIM0PRD2 *(( ioport volatile unsigned int *) 0x1813)
#define TIAFR *(( ioport volatile unsigned int *) 0x1C14)
#define TIM0TCR *(( ioport volatile unsigned int *) 0x1810)

#endif


