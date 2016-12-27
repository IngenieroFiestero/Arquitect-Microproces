#include <stdio.h>

//gcc -o pr1_4 pr1_4.c 
int main(void){
	printf("Sustitucion de caracteres 'a' por 'e' sin usar vectores...\n");
	char cadenaprima[30];
    char cadenaOrigin[30];
	fgets(cadenaOrigin,30,stdin);
	char *p_vec = cadenaOrigin;
	char *p_vec2 = cadenaprima;
	while(*p_vec != '\0'){
		if(*p_vec == 'a'){
			*p_vec2 = 'e';
		}else{
			*p_vec2 = *p_vec;
		}
		p_vec++;
		p_vec2++;
	}
	printf(cadenaprima);
}