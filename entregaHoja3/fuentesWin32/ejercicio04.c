/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 4. Recibe una palabra, y determina
 				 si es un palindromo*/

#include <stdio.h>
#include <string.h>

int es_palindromo (char cad[]);

int main(void)
{
	char str1[30];
	
	printf("Escriba una palabra : ");
	gets(str1);


	if(es_palindromo(str1))
		printf("\"%s\" es una palabra palindroma", str1);
	else
		printf("\"%s\" no es una palabra palindroma", str1);

	return 0;
}

/*Determina si una cadena es un palindromo*/
int es_palindromo (char cad[])
{
	int izq,drcha,salir;
	izq = 0;
	drcha = strlen(cad) - 1;
	salir = 0;
	
	/*Recorreremos la palabra comparando por los extremos*/
	while((izq<=drcha) && !salir)
	{	
		if(cad[izq] != cad[drcha])
			salir = 1;
		izq++;
		drcha--;
	}
	
	return !salir;
	
}
