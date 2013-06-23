/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 7. Contiene estructuras para almacenar polinomios
				 y permite que se realicen sumas de los mismos*/

#include <stdio.h>
#include <stdlib.h>

/*Definiciones para tipo lista*/
struct tipoNodoPolinomio{
	int coeficiente;
	unsigned int exponente; 
	struct tipoNodoPolinomio *sig;
	};
typedef struct tipoNodoPolinomio tNodoPolinomio;
	
/*Cabeceras de funciones auxiliares*/
void insertar (tNodoPolinomio **lista, int coeficiente, int exponente);
void recorrer (tNodoPolinomio*lista);
void liberar (tNodoPolinomio *lista);
void crearPolinomio (tNodoPolinomio **polinomio);
void sumarPolinomios (tNodoPolinomio **pol1, tNodoPolinomio *pol2);

int main(void)
{
	tNodoPolinomio *pol1,*pol2;
		
	pol1 = NULL;
	pol2 = NULL;
	
	crearPolinomio(&pol1);
	crearPolinomio(&pol2);
	
	printf("\nPolinomio 1 : ");
	recorrer(pol1);
	printf("\nPolinomio 2 : ");
	recorrer(pol2);
	
	printf("\nSuma de ambos : ");
	sumarPolinomios(&pol1,pol2);
	recorrer(pol1);

	liberar(pol1);
	liberar(pol2);
	
	return 0;
}
		
	
/* Funciones auxiliares 								*/
/********************************************************/

/*Crea un polinomio */
void crearPolinomio (tNodoPolinomio **polinomio)
{
	int j,i,coefAux;
	unsigned int expAux;
	
	printf("¿Cuantos terminos tiene su polinomio? : ");
	scanf("%i", &i);
	
	for (j=0; j<i; j++)
	{
		printf("Coeficiente del termino %i : ", j+1);
		scanf("%i", &coefAux);
		printf("Exponente del termino %i : ", j+1);
		scanf("%i", &expAux);
		
		insertar(polinomio,coefAux,expAux);
	}
	
}


/*Suma los valores de dos polinomios. El resultado se devuelve en el primero*/
void sumarPolinomios (tNodoPolinomio **pol1, tNodoPolinomio *pol2)
{

	while (pol2 != NULL)
	{
		insertar(pol1,pol2->coeficiente,pol2->exponente);
		pol2 = pol2->sig;
	}
}


/*Inserta un nodo al final de la lista*/
void insertar (tNodoPolinomio **lista, int coeficiente, int exponente)
{
	tNodoPolinomio *p1, *p2, *p3;

	p1 = *lista;
	int encontrado;
	
	/*Si es el primer elemento*/
	if(p1==NULL)
	{
		p1 = malloc(sizeof(tNodoPolinomio));
		
		if (p1 != NULL)
		{
			/*Guardamos info, y hacemos q ese nodo apunte a null*/
			p1->coeficiente = coeficiente;
			p1->exponente = exponente;
			p1->sig = NULL;
			*lista = p1;
		}
		
	}else{
		/*Si habia mas elementos */
		
		/*Primero recorremos, para ver si ya existe ese coeficiente, y en ese caso sumarlo*/
		encontrado = 0;
		p3 = p1;
		while((p3 != NULL) && (!encontrado))
		{
			if(p3->exponente==exponente)
			{
				p3->coeficiente += coeficiente;
				encontrado = 1;
			}else{
				p3 = p3->sig;
			}
		}	
		
		/*Si no existia, lo guardamos en un nuevo nodo al final*/
		if (!encontrado){
			/*Vamos hacia el ultimo*/
			while(p1->sig!=NULL)
			p1 = p1->sig;

			p2 = malloc(sizeof(tNodoPolinomio));
		
			if(p2 != NULL)
			{
				/*Guardamos info en nuevo nodo, y hacemos que apunte a null*/
				p2->coeficiente = coeficiente;
				p2->exponente = exponente;
				p2->sig = NULL;
			
				/*Y lo apuntamos desde el que anteriormente era el ultimo*/
				p1->sig = p2;
			}
		}
		
		
	}
		
}	


/*Recorre la lista mostrando su contenido por la salida estandar*/
void recorrer (tNodoPolinomio *lista)
{
	while(lista != NULL)
	{
		if(lista->sig == NULL)
			if (lista->exponente>0)
				printf("%ix^%i", lista->coeficiente, lista->exponente);
			else
				printf("%i", lista->coeficiente);
		else
			if (lista->exponente>0)
				printf("%ix^%i + ", lista->coeficiente, lista->exponente);
			else
				printf("%i + ", lista->coeficiente);	
				
		lista = lista->sig;
	}
}
		

/*Libera todos los nodos de la lista*/
void liberar(tNodoPolinomio *lista)
{
	tNodoPolinomio *pAux;
	
	while(lista != NULL)
	{
		pAux = lista;
		lista = lista->sig;
		free(pAux);
	}
	
}
