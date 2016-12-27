### Practica 2: uso del Timer, lectura pulsadores y contador usando los pulsadores

1. Ejercicio 1: Lectura del estado de los pulsadores.

    Esta función devuelve los valores siguientes:

    0 -> si no hay ningún switch pulsado

    1 -> si se ha pulsado el sw1

    2 -> si se ha pulsado el SW2

    3 -> si se han pulsado los dos switches

    Si se repite en dos llamadas consecutivas el mismo valor,la función devuelve un 0
2. Ejercicio 2: Contador ascendente/descendente.

    Diseñe una aplicación que controle un contador de 4 bits (b 3 b 2 b 1 b 0 ) con saturación (0-15) según el esquema siguiente:
    * Pulsación de sw1 incrementa en una unidad el contador hasta llegar a 15.
    * Pulsación de sw2 decrementa en una unidad el contador hasta llegar a 0.
    
    El valor actual del contador se mostrará en los 4 leds (VRAmAz → b 3 b 2 b 1 b 0 )
3. Ejercicio 3: Encendido intermitente de los leds.
    
    Se trata de encender el led amarillo con una frecuencia de 1 Hz, el led deberá estar encendido 500ms y apagado otros 500ms.
    Para contar 500 ms utilizaremos uno de los contadores de ciclos de reloj de 32 bits (timers) de los que dispone el DSP