#include <stdio.h>

//gcc -o pr1_3 pr1_3.c 
int main(void){
	//Sumatorio primeros N numeros naturales
	printf("Suma de los n primeros numeros naturales:\n");
	int n,i;
	scanf("%d",&n);
	int suma = 0;
	for(i=0; i <= n; i++){
		suma += i;
	}
	printf("Resultado suma: %d\n",suma);
}