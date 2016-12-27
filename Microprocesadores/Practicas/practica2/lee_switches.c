/*
* unsigned int lee_switches()
*
* Esta funcion devuelve los valores siguientes:
* 0 -> si no hay ningun switch pulsado
* 1 -> si se ha pulsado el sw1
* 2 -> si se ha pulsado el sw2
* 3 -> si se han pulsado los dos switches
* Si se repite en dos llamadas consecutivas el mismo valor,
* la funcion devuelve un 0
*/
#include "SEmP_5515.h"
#include "lee_switches.h"


unsigned int lee_switches ()
{
    typedef enum {s_pls_reposo, s_pls_1, s_pls_2, s_pls_12} pls_estados_t;
    static pls_estados_t pls_estado=s_pls_reposo;
    unsigned int dato_ADC,dato_leido,pulsacion;
    SARCTRL=0xB400; // Inicio conversion canal 3
    while (SARDATA & 0x8000); // Conversion finalizada
    dato_ADC=SARDATA & 0x3FF;
    dato_leido=Error;
    if ((dato_ADC > (SW1-rng)) && (dato_ADC < (SW1+rng))) dato_leido=1;
    if ((dato_ADC > (SW2-rng)) && (dato_ADC < (SW2+rng))) dato_leido=2;
    if ((dato_ADC > (SW12-rng)) && (dato_ADC < (SW12+rng))) dato_leido=3;
    if ((dato_ADC > (NoKey-rng))) dato_leido=0;
    pulsacion=0;
    switch (pls_estado)
    {
        case s_pls_reposo: if (dato_leido==1) {pls_estado=s_pls_1; pulsacion=1;}
        else if (dato_leido==2) {pls_estado=s_pls_2; pulsacion=2;}
        else if (dato_leido==3) {pls_estado=s_pls_12;pulsacion=3;}
        break;
        case s_pls_1: if ((dato_leido!=1)&&(dato_leido!=4)) pls_estado=s_pls_reposo;
        break;
        case s_pls_2: if ((dato_leido!=2)&&(dato_leido!=4)) pls_estado=s_pls_reposo;
        break;
        case s_pls_12: if (dato_leido==0) pls_estado=s_pls_reposo;
    }
    return pulsacion;
}

