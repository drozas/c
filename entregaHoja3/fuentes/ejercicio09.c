/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 9. Lee dos ficheros de entradas con enteros.
				 Los guarda ordenadamente en una estructura dinamica, y
				 los escribe en un nuevo fichero*/

#include <stdio.h>
#include <stdlib.h>

struct tipoNodo{
	int valor;
	struct tipoNodo *sig;
	};
typedef struct tipoNodo tNodo;
	
/*Cabeceras de funciones auxiliares*/
void insertar_ordenado (tNodo **mat, int val);
void guardar (tNodo *mat);
void liberar(tNodo *mat);


int main(void)
{
	FILE *fichero_origen1 = fopen("fent1.dat", "rb");
	FILE *fichero_origen2 = fopen("fent2.dat", "rb");
	tNodo *lista;
	int dato;
	
	lista = NULL;
	
	/*Almacenamos ordenadamente en nuestra lista el contenido de ambos ficheros*/
	while(fread(&dato, sizeof(dato), 1, fichero_origen1)==1)
		insertar_ordenado(&lista, dato);
		
	while(fread(&dato, sizeof(dato), 1, fichero_origen2)==1)
		insertar_ordenado(&lista, dato);

	/*Lo guardamos en un fichero, y liberamos la estructura*/
	guardar(lista);
	liberar(lista);
	
	fclose(fichero_origen1);
	fclose(fichero_origen2);

	return 0;
	
}


/* Funciones auxiliares 								*/
/********************************************************/

/*Inserta un nodo en funcion de su valor en la lista */
void insertar_ordenado(tNodo **lista, int valor)
{
	tNodo *pActual, *pNuevo, *pAnterior;
	
	pActual = *lista;
	pAnterior = *lista;
	
	/*Buscamos su posicion*/
	while((pActual !=NULL) && (pActual->valor <valor))
	{
		pAnterior = pActual;
		pActual = pActual->sig;
	}

	/*Reservamos memoria para el nuevo nodo*/
	pNuevo = malloc(sizeof(tNodo));
	if (pNuevo!=NULL)
	{
		pNuevo->valor = valor;
	
		/*Y enlazamos*/
		if(pAnterior==NULL || pAnterior==pActual)
		{
			/*Insertamos al principio*/
			pNuevo->sig = pAnterior;
			*lista = pNuevo;
		}else{
			/*Insertamos entre medias o al final*/
			pNuevo->sig = pActual;
			pAnterior->sig = pNuevo;
		}
	}
	
}
	
/*Recorre la lista guardando su contenido en un fichero de texto*/
void guardar (tNodo *lista)
{
	FILE *fichero_destino = fopen("fsal.txt", "wt");
	
	int i = 1;
	while(lista != NULL)
	{
		if (i%3 != 0)
			fprintf(fichero_destino,"%i ", lista->valor);
		else
			fprintf(fichero_destino,"%i\n", lista->valor);
		
		i++;
		lista = lista->sig;
	}
	
	fclose(fichero_destino);
}
	
	
/*Libera todos los nodos de la matriz*/
void liberar(tNodo *lista)
{
	tNodo *pAux;
	
	while(lista!= NULL)
	{
		pAux = lista;
		lista = lista->sig;
		free(pAux);
	}	
}
