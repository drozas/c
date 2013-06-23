/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 3. Sustituye los caracteres en blanco
      			 de una cadena por guiones, y los cuenta*/

#include <stdio.h>
#include <string.h>

int sustituir (char cad[]);

int main(void)
{

	
	char str1[100];
	int cont;
	
	printf("Escriba una frase (max 100 caracteres) : ");
	gets(str1);
	
	printf("Cadena original: \"%s\"\n", str1);
	cont = sustituir(str1);
	printf("Cadena sustituida : \"%s\"\n", str1);
	printf("Se han realizado %i sustituciones\n", cont);
	
	return 0;
}

/* Sustituye los espacios en blanco por guiones en un string*/	
int sustituir (char cad[])
{
	int i,cont;
	
	for(i=0, cont=0; i<strlen(cad); i++)
		if(cad[i] == ' ')
		{
			cad[i]= '-';
			cont++;
		}
	return cont;
}
