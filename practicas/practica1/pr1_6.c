#include <stdio.h>

//gcc -o pr1_6 pr1_6.c 
int main(void){
	//COLA FIFO
	printf("\nImplementacion de una Cola FIFO:\nLista Comandos:\n	-add: Incluye frase\n	-rm: Elimina frase\n	-print: Imprimir por pantalla \n	-exit: Salir\n");
	int salir = 0,i;
	int contenido[100];
	int maxPos = -1;
	for(i=0; i < 100; i++){
		contenido[i] == 0;
	}
	while(!salir){
		char command[30];
		fgets(command,30,stdin);
		if(command[0] == 'e' && command[1] == 'x' && command[2] == 'i' && command[3] == 't'){
            //Exit (exit)
			salir = 1;
		}else{
			if(command[0] == 'p' && command[1] == 'r' && command[2] == 'i' && command[3] == 'n' && command[4] == 't'){
                //Print (print)
				printf("Valores en la cola: ");
				for(i = 0; i <= maxPos; i++){
					printf("%d ",contenido[i]);				
				}
				printf("\n");
			}else if(command[0] == 'a' && command[1] == 'd' && command[2] == 'd'){
                //Add (add)
				printf("Ingrese valor Numerico: \n");
				int valor;
				scanf("%d",&valor);
				maxPos++;
				contenido[maxPos] = valor;
			}else if(command[0] == 'r' && command[1] == 'm'){
                //Remove (rm)
				for(i = 1; i < maxPos; i++){
					contenido[i-1] = contenido[i];
				}
				contenido[maxPos] = 0;
				maxPos--;
			}
		}
	}
}