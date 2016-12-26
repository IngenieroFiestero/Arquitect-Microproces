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
int NThreads = 5;
//Sum 420
//gcc -pthread -o ej_threads ej_threads3.c 
void *func(void *p);
struct registro{
    int inicio;
    int salto;
    int final;
};
void main(){
    int total = 0;
    int vsuma[NThreads];
    pthread_t th[NThreads];
    struct registro reg[NThreads];
    for(int i=0; i < NThreads; i++){
        struct registro r1;
        r1.inicio =i;
        r1.salto =NThreads;
        r1.final =N;
        reg[i] = r1;
        pthread_create(&th[i],NULL,func,(void *)&reg[i]);
    }
    for(int i=0; i < NThreads; i++){
        pthread_join(th[i],(void **) &vsuma[i]);
        total +=(vsuma[i]);
    }
    printf("Suma %i\n",total);
    for(int i=0; i < N; i++){
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

