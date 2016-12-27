/*
 * main.c
 */


#include "SEmP_5515.h"
#include "lee_switches.h"
#include "contador.h"

 void main(void){
	//Configuramos primero la CPU
	CPU_IVPD=0x04FE;
	CPU_IVPH=0x04FE;

	//Configuramos despuus la GPIO
	//Valores de inicio de las entradas y las salidas
	IODIR1=0xC000;
	IODIR2=0x03;
	IODATAOUT1= 0xC000;
	IODATAOUT2= 0x03;
	//Configuracion previa del conversor
	SARCLKCTRL=0x0031;
	SARPINCTRL=0x3100;
	SARGPOCTRL=0;

	/*unsigned int pulsacion;
	unsigned int contar;
	uint16_t cont1;
	uint16_t cont2;*/

	//TIMER
	TIM0PRD1=0xBC1F;
	TIM0PRD2=0x00BE;
	TIAFR=0x0000;
	TIM0TCR=0x8003;
	while(1){
		/*contar=contador(pulsacion);
		cont1 = (contar >> 2);
		cont2 = (contar << 14);
		IODATAOUT1 = cont2 ^~ 0x0003;
		IODATAOUT2 = cont1 ^~ 0xC000;*/

		//Timer

		if(TIAFR==0x0001){
			TIM0TCR=0x8003;
			IODATAOUT2 ^=0x02;
			TIAFR=0x1;
		}
	}


}

