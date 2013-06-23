/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 6. Decide si un caracter aparece
				 en una cadena de caracteres*/

#include <stdio.h>
#include <string.h>


#define N_CAR 100

int main(void)
{
	char str1[N_CAR];
	char car;
	int pos[N_CAR], i, j;/*el vector pos almacena las posiciones donde aparece*/
	
	printf("Escriba una frase : ");
	gets(str1);
	
	printf("Escriba un caracter : ");
	scanf("%c", &car);
	
	for(i=0, j=0; i<strlen(str1); i++)
	{
		if(str1[i]==car)
		{
			pos[j] = i;
			j++;
		}
	}
	
	if (j>0)
	{
		printf("Se ha encontrado el caracter %c %i veces, en las posiciones : \n", car, j);
		for(i=0; i<j;i++)
			printf("%i , ", pos[i]);
	}else{
		printf("El caracter %c no se encuentra en la palabra\n", car);
	}
	
	return 0;
}
