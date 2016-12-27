#include <stdio.h>
#include <string.h>
#define N 30
//gcc -o pr1_7 pr1_7.c 
int main(void){
	printf("Introducir una cadena de texto:\n");
	char cadenaOrigin[N];
	fgets(cadenaOrigin,N,stdin);
	printf("Caracter a imprimir por pantalla empezando por el final:\n");
	int valor;
	scanf("%d",&valor);
	int longitud =(unsigned)strlen(cadenaOrigin);
	printf("El caracter numero %d empezando por el final es: %c \n",valor ,cadenaOrigin[longitud - valor - 1]);
}