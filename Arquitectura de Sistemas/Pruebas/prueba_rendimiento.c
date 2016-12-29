#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//gcc -o prueba_rendimiento prueba_rendimiento.c
/*
    Ejercicio simple para comprobar que es mas rapido al acceder a un valor concreto del vector repetidamente:
    Acceder directamente a el como vector[i] o guardarlo en otra variable y acceder solo a esa variable.
*/
int vector[5] = {1,2,3,4,5};
void main(){
    clock_t t_ini, t_fin;
    double secs;
    int pos =1;
    int valor = 0;
    t_ini = clock();
    for(int j=0;j<50000;j++){
        for(int i=0;i<500;i++){
            valor =vector[pos];
        }   
    }
    t_fin = clock();
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("%.16g milisegundos\n", secs * 1000.0);
    int valor2 = 0;
    t_ini = clock();
    for(int j=0;j<50000;j++){
        for(int i=0;i<500;i++){
            valor2 =valor;
        }   
    }
    t_fin = clock();
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("%.16g milisegundos\n", secs * 1000.0);
}
/*
Salida
84.994 milisegundos
89.26000000000001 milisegundos
*/