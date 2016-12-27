#include <stdio.h>

//gcc -o pr1_5 pr1_5.c 
int main(void){
	int i,suma;
	printf("Invertir el orden de las palabras en una frase:\n");
	char cadenaInv[30];
	char cadena2[30];
	fgets(cadena2,30,stdin);
	for(i=0; i < 30; i++){
		cadenaInv[i] = ' ';	
	}
	int salir = 0;
	int pos = 0;
	int lastSpace;
	while(!salir){
		if(!(cadena2[pos] > 31 && cadena2[pos] < 127)){
			salir = 1;
			lastSpace = pos-1;
		}else{
			pos++;
		}
		
	}
	int z;
	suma = 0;
	for(z=pos; z >= 0; z--){
		if(cadena2[z] == ' '){
			int j;
			for(j = lastSpace; j > z; j--){
				cadenaInv[suma + (j-z)-1] = cadena2[j];
			}
			suma = suma + lastSpace-z+1;
			lastSpace = z-1;
		}
	}
	int j;
	for(j = lastSpace; j >= 0; j--){
		cadenaInv[suma + j] = cadena2[j];
	}
	printf("%s\n",cadenaInv);
}