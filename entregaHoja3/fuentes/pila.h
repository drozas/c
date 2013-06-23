/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 12. Fichero de cabecera para el TAD pila*/

#include <stdio.h>
#include <stdlib.h>

struct tipoNodo{
	int valor;
	struct tipoNodo *sig;
	};
typedef struct tipoNodo tNodo;

void CrearVacia (tNodo **pila);
void InsertarElemento(tNodo **pila, int valor);
int DevolverCima(tNodo **pila);
