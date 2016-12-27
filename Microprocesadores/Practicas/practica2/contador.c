/*
 * contador.c
 * Cuenta usando los switches.
 * Si se pulsa el switch1 se aumenta el contador en uno, 
 * si se pulsa el switch2 se disminuye en 1 hasta un maximo de 15 y un minimo de 0.
 */
#include "contador.h"

unsigned int contador (unsigned int pulsacion){
	static uint16_t var_contador=0;
		pulsacion=lee_switches();
		if(pulsacion==1 && var_contador < 15){
			var_contador++;
		}else if (pulsacion==2 && var_contador > 0){
			var_contador--;
		}

	return var_contador;
}


