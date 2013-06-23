/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 10. Procesa un texto guardando las lineas en
				 una estructura dinamica, contando las vocales, etc.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Tipo nodo para lista de listas estaticas*/
struct tipoNodo2{
	char palabra[50];
	int linea[100];
	int ultLinea;
  	struct tipoNodo2 *sig;
	};
typedef struct tipoNodo2 tNodo2;


void recorrer (tNodo2 *lista);
void insertar (tNodo2 **lista, char palabra[], int linea);
void liberar(tNodo2 *lista);

int main(void)
{
	
	
	tNodo2 *lista;
	
	lista = NULL;
	
	insertar(&lista,"cadena1",2);
	insertar(&lista,"cadena2",3);
	recorrer(lista);
	
 		
  return 0;
}


/*Inserta un nodo al final de la lista de car*/
void insertar (tNodo2 **lista, char palabra[], int linea)
{
	tNodo2 *p1, *p2;

	p1 = *lista;
	
	/*Si es el primer elemento*/
	if(p1==NULL)
	{
		p1 = malloc(sizeof(tNodo2));
		
		if (p1 != NULL)
		{
			/*Guardamos info, y hacemos q ese nodo apunte a null*/
			strcpy(p1->palabra,palabra);
			p1->linea[p1->ultLinea] = linea;
			p1->ultLinea = 0;
			p1->ultLinea++;
			
			p1->sig = NULL;
			*lista = p1;
		}
		
	}else{
		/*Si habia mas elementos */
		
		/*Vamos hacia el ultimo*/
		while(p1->sig!=NULL)
			p1 = p1->sig;

		p2 = malloc(sizeof(tNodo2));
		
		if(p2 != NULL)
		{
			/*Guardamos info en nuevo nodo, hacemos que apunte a null*/
			strcpy(p2->palabra,palabra);
			p2->linea[p2->ultLinea] = linea;
			p1->ultLinea = 0;
			p2->ultLinea++;
			p2->sig = NULL;
			
			/*Y lo apuntamos desde el que anteriormente era el ultimo*/
			p1->sig = p2;
		}
	}
}


/*Recorre la lista mostrando su contenido por la salida estandar*/
void recorrer (tNodo2 *lista)
{
	while(lista != NULL)
	{
		getc();
		printf("Palabra : %s. Linea0= %i.Valor de ultima linea : %i/n", lista->palabra,lista->linea[0],lista->ultLinea);
	}
}

/*Libera todos los nodos de la lista*/
void liberar(tNodo2 *lista)
{
	tNodo2 *pAux;
	
	while(lista != NULL)
	{
		pAux = lista;
		lista = lista->sig;
		free(pAux);
	}
	
}
