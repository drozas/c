/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 6. Se lee una cadena por pantalla y se almacena
				 cada caracter en una lista. Posteriormente se eliminan todos
				 los espacios en blanco de dicha lista*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Definiciones para tipo lista*/
struct tipoNodoCaracter{
	char car;
	struct tipoNodoCaracter *sig;
	};
typedef struct tipoNodoCaracter tNodoCar;


int main(void)
{
	char frase[50];
	tNodoCar *lista, *pAux, *indice;
	int i;
	
	
	lista = NULL;
	pAux = NULL;
	indice = NULL;
	
	printf("Introduce una frase (max. 50 car.): ");
	gets(frase);

	/*Insertamos al reves, para despues tenerla ordenada*/
	for(i=(strlen(frase))-1; i>=0; i--)
	{
		
		/*Reservamos memoria, e introducimos informacion*/
		pAux = (tNodoCar*)malloc(sizeof(tNodoCar));
		pAux->car = frase[i];
		
		/*Insercion, dependiendo de si es o no el primer elemento*/
		if (lista==NULL)
		{
			pAux->sig = NULL;
			lista = pAux;
		}else{
			pAux->sig = lista;
			lista = pAux;
		}
		
		printf("lista->sig = %p, lista->car = %c\n", lista->sig, lista->car);
	}

	/*Recorremos la lista*/
	indice = lista;
	//printf("indice antes : %c\n", indice->car);
	while(indice != NULL)
	{
		printf(" %c ->", indice->car);
		indice = indice->sig;
	}
	
	/*Recorremos la lista eliminando nulos*/
	indice = lista;
	while(indice != NULL)
	{
		if(indice->car=='a')
		{
			
			pAux = indice-1;
			printf("Valor del anterior %c \n", pAux->car);	
		}
		//printf(" %c ", indice->car);
		indice = indice->sig;
	}

	return 0;
}
