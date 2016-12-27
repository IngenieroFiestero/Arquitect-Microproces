#include "SEmP_5515.h"
/*
 * main.c
 */
void main(void) {
	long unsigned int i;
	//situo los vectores de interrupcion
	CPU_IVPD=0x04DE;
	CPU_IVPH=0x04FE;
	//Configuro GPIO para acceder a los leds
	// y valores de inicio
	IODIR1 = 0xC000;
	IODIR2= 0x03;
	IODATAOUT1= 0xC000;
	IODATAOUT2= 0x03;
	
	while(1)
	{
		IODATAOUT1 ^= 0x4000;//Azul
		for (i=0;i<2000000;i++);
		IODATAOUT1 ^= 0x4000;//Azul
		IODATAOUT1 ^= 0x8000;//Naranja
		for (i=0;i<2000000;i++);
		IODATAOUT1 ^= 0x8000;//Naranja
		IODATAOUT2 ^= 0x01;//Rojo
		for (i=0;i<2000000;i++);
		IODATAOUT2 ^= 0x01;//Rojo
		IODATAOUT2 ^= 0x02;//Verde
		for (i=0;i<2000000;i++);
		IODATAOUT2 ^= 0x02;//Verde
		IODATAOUT2 ^= 0x01;//Rojo
		for (i=0;i<2000000;i++);
		IODATAOUT2 ^= 0x01;//Rojo
		IODATAOUT1 ^= 0x8000;//Naranja
		for (i=0;i<2000000;i++);
		IODATAOUT1 ^= 0x8000;//Naranja

	}
}
