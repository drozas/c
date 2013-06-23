/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 12. Utiliza el TAD pila,  realizando
				 inserciones y extracciones del mismo*/

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main(void)
{
	tNodo *mi_pila;
	int valAux;
	
	CrearVacia(&mi_pila);
	InsertarElemento(&mi_pila, 1);
	InsertarElemento(&mi_pila, 2);
	InsertarElemento(&mi_pila, 3);
	valAux = DevolverCima(&mi_pila);
	printf("Extrayendo valor %i \n", valAux);
	valAux = DevolverCima(&mi_pila);
	printf("Extrayendo valor %i \n", valAux);
	valAux = DevolverCima(&mi_pila);
	printf("Extrayendo valor %i \n", valAux);

	return 0;
}
