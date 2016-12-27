#include <stdio.h>
#include <string.h>
//gcc -o miprog pr2_1.c 
//./miprog a b c 0.1 raimundo 
int main(int argc,char *argv[]){
    //Eliminamos el ./
    int caracteres = (sizeof argv[0])-2;
    printf("%.*s\n", caracteres, argv[0]+ 2);
    for(int i=1; i < argc;i++){
        printf("%s\n",argv[i]);
        caracteres += strlen(argv[i]) + 1;//Caracter extra del espacio
    }
    printf("Numero de palabras: %d\nNumero de caracteres: %d\n",argc,caracteres);
}