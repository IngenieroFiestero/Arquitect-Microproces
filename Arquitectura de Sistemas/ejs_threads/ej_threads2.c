#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define N 20
int v1[N] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int v2[N] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int v3[N];

//Sum 420
//gcc -pthread -o ej_threads ej_threads2.c 
void *func(void *p);
struct registro{
    int inicio;
    int salto;
    int final;
};
void main(){
    int total = 0;
    int suma1 = 0, suma2 = 0;
    pthread_t th1;
    pthread_t th2;
    struct registro r1,r2;
    r1.inicio =0;
    r1.salto =2;
    r1.final =N;
    r2.inicio =1;
    r2.salto =2;
    r2.final =N;
    pthread_create(&th1,NULL,func,(void *)&r1);
    pthread_create(&th2,NULL,func,(void *)&r2);
    pthread_join(th1,(void **) &suma1);
    total +=suma1;
    pthread_join(th2,(void **) &suma2);
    total +=suma2;
    printf("Suma %i\n",total);
    for(int i=0; i < 20; i++){
        printf("%i:%i ",i,v3[i]);
    }
    printf("\n");
}

void *func(void *p){
    int i, suma = 0;
    int inicio, salto,final;
    inicio = ((struct registro *)p)->inicio;
    salto = ((struct registro *)p)->salto;
    final = ((struct registro *)p)->final;
    for(int i = inicio; i < final; i+=salto){
        int sum = v1[i] + v2[i];
        v3[i] = sum;
        suma += sum;
    }
    pthread_exit((void *)suma);
}

