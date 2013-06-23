/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 5. Se lee una cadena por pantalla y se almacena
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
	
/*Cabeceras de funciones auxiliares*/
void insertar (tNodoCar **lista, char car);
void recorrer (tNodoCar *lista);
void eliminar_espacios (tNodoCar *lista);
void liberar (tNodoCar *lista);

int main(void)
{
	char frase[50];
	tNodoCar *lista;
	int i;
		
	lista = NULL;
	
	printf("Introduce una frase (max. 50 car.): ");
	gets(frase);
	
	
	for(i=0; i<strlen(frase); i++)
	{
		insertar(&lista, frase[i]);
	}
	
	printf("\nCotenido inicial de la lista : ");
	recorrer(lista);
	
	printf("\nCotenido posterior de la lista : ");	
	eliminar_espacios(lista);
	recorrer(lista);	
	liberar(lista);
	
	return 0;
}
		
	
/* Funciones auxiliares 								*/
/********************************************************/

/*Inserta un nodo al final de la lista */
void insertar (tNodoCar **lista, char car)
{
	tNodoCar *p1, *p2;

	p1 = *lista;
	
	/*Si es el primer elemento*/
	if(p1==NULL)
	{
		p1 = malloc(sizeof(tNodoCar));
		
		if (p1 != NULL)
		{
			/*Guardamos info, y hacemos q ese nodo apunte a null*/
			p1->car = car;
			p1->sig = NULL;
			*lista = p1;
		}
		
	}else{
		/*Si habia mas elementos */
		
		/*Vamos hacia el ultimo*/
		while(p1->sig!=NULL)
			p1 = p1->sig;

		p2 = malloc(sizeof(tNodoCar));
		
		if(p2 != NULL)
		{
			/*Guardamos info en nuevo nodo, hacemos que apunte a null*/
			p2->car = car;
			p2->sig = NULL;
			
			/*Y lo apuntamos desde el que anteriormente era el ultimo*/
			p1->sig = p2;
		}
	}
		
}	

/*Recorre la lista mostrando su contenido por la salida estandar*/
void recorrer (tNodoCar *lista)
{
	while(lista != NULL)
	{
		printf("%c", lista->car);
		lista = lista->sig;
	}
}
		
/*Recorre la lista eliminando los nodos cuyo contenido
  es un caracter en blanco*/
void eliminar_espacios (tNodoCar *lista)
{
	tNodoCar *pAux;
	
	pAux = NULL;
	
	while(lista->sig != NULL)
	{
		/*Si el nodo proximo contiene caracter en blanco*/	
		if((lista->sig)->car == ' ')
		{
			/*Lo borramos, y apuntamos desde nuestro nodo actual al que apuntaba*/
			pAux = lista->sig;
			lista->sig = pAux->sig;
			free(pAux);
		}else{
			/*Si no, seguimos recorriendo la lista*/	
			lista = lista->sig;
		}
	
	}
}

/*Libera todos los nodos de la lista*/
void liberar(tNodoCar *lista)
{
	tNodoCar *pAux;
	
	while(lista != NULL)
	{
		pAux = lista;
		lista = lista->sig;
		free(pAux);
	}
	
}
