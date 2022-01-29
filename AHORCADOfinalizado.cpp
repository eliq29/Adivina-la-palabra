#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	
	char letra;
	char palabra [30];
	char palabraOculta [30] = {};
	int i=0, intentos=5, flag=0, aciertos=0, palabraRepetida=0;
	
	printf("\t ADIVINA LA PALABRA \n\n");
	printf("Escribe la palabra que quieres adivinar:  ");
	scanf("%s", palabra);
	
	
	
	for (i=0; i<strlen(palabra); i++){
		palabraOculta[i] = '-';
	}
	do{
		if(palabraRepetida == 1){
			printf ("Ya se ha introducido esa letra antes \n\n");
			palabraRepetida = 0;
		}
		
		
		printf ("Palabra oculta: %s\n\n", palabraOculta);
		printf ("Letras acertadas: %d\n", aciertos);
		printf ("Fallos restantes: %d\n\n", intentos);
		printf ("Introduzca una letra: ");
		scanf ("%s", &letra);
		
		int palabraCorrecta=0, opcion=0;
		for (i=0; i<strlen(palabra); i++){
			if (palabra[i] == letra && palabraOculta[i] !=letra){
				palabraOculta[i] = letra;
				aciertos++;
				palabraCorrecta = 1;
			}else if(palabraOculta[i] == letra){
				palabraRepetida = 1;
				palabraCorrecta = 1;
			}
		}
		if(!palabraCorrecta){
			intentos -= 1;
		}
		if(!strcmp(palabra, palabraOculta)){
			
			printf("!FELICITACIONES, GANASTE! \n LA PALABRA ES: %s\n", palabra);
			flag = 1;
		}else if(intentos == 0){
			
			printf("INTENTALO DE NUEVO : A PALABRA ERA...: %s", palabra);
			flag = 1;
		}
	}while (flag != 1);
}
