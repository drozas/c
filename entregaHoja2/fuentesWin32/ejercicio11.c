/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 11. Creacion de lista enlazada, y recorrido
				 para obtener la suma de sus numeros*/

#include <stdio.h>
#include <stdlib.h>

/*Definiciones para tipo lista*/
struct tipoNodo{
	float info;
	struct tipoNodo *sig;
	};
typedef struct tipoNodo tNodo;

ejercicio10.c
int main(void)
{
	tNodo *lista, *pAux, *indice;
	int n_elementos, i;
	float valorAux, total;
	
	lista = NULL;
	pAux = NULL;
	indice = NULL;
	total = 0.0;
	
	do
	{
		printf("¿Cuantos elementos quieres insertar? : ");
		scanf("%i", &n_elementos);
	}while(n_elementos<1);
	

	for(i=0; i<n_elementos; i++)
	{
		printf("Inserta un valor : ");
		scanf("%f", &valorAux);
		
		/*Reservamos memoria, e introducimos informacion*/
		pAux = (tNodo*)malloc(sizeof(tNodo));
		pAux->info = valorAux;
		
		/*Insercion, dependiendo de si es o no el primer elemento*/
		if (lista==NULL)
		{
			pAux->sig = NULL;
			lista = pAux;
		}else{
			pAux->sig = lista;
			lista = pAux;
		}
	}
	
	/*Recorremos la lista, y hacemos el sumatorio*/
	indice = lista;
	while(indice != NULL)
	{
		total = total + indice->info;
		indice = indice->sig;
	}
	
	printf("\n----------------------------------------------------------\n");
	printf("Suma total de los elementos de la lista : %.2f", total);
	printf("\n----------------------------------------------------------\n");
	
	/*Por ultimo, liberamos la memoria*/
	while(lista != NULL)
	{
		indice = lista;
		lista = lista->sig;
		free(indice);
	}
		
	return 0;
}
