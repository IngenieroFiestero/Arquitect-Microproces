#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int v1[20] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int v2[20] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//Sum 420
void main(){
    int v3[20];
    int suma = 0;
    printf("Vector : ");
    for(int i=0;i < 20;i++){
        int sum = v1[i]+v2[i];
        printf("%i:%i ",i,sum);
        v3[i]=sum;
        suma +=sum;
    }
    printf("Suma %i/n",suma);
}