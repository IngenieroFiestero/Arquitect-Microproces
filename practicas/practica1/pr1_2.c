#include <stdio.h>

//gcc -o pr1_2 pr1_2.c 
int main(void){
	//Sustitucion de letras 'a' por 'e'
	printf("Escribe palabras para sustituir la \'a\' por \'e\'\n");
	char cadenaOrigin[30];
	char cadena[30];
	fgets(cadenaOrigin,30,stdin);
	int i;	
	for(i=0; i < 30; i++){
		if(cadenaOrigin[i] == 'a'){
			cadena[i] = 'e';
		}else{
			cadena[i] = cadenaOrigin[i];
		}
	}
	printf(cadena);
}