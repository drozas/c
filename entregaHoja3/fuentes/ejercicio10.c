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

struct tipoNodo{
	struct tipoNodo *sig;
	char car; 
	};
typedef struct tipoNodo tNodo;

void recorrer (tNodo *lista);
void insertar (tNodo **lista, char car);
void liberar(tNodo *lista);
void inicializar_vocales(int vocales[]);


int main(void)
{
	FILE *fichero = fopen("prueba.txt", "rt");
	int n;
	tNodo *lista;
	lista = NULL;
	int vocales[5];
	
	int i;		

	if (fichero!=NULL)
	{
		while(!feof(fichero))
		{
			n = fgetc(fichero);

			if (n != EOF)
			{
				insertar(&lista, n);
			}
	
		}
		fclose(fichero);
		
		/*Recorremos mostrando la info*/
		recorrer(lista);
		/*Por ultimo liberamos la memoria*/
		liberar(lista);
	
	}else{
		printf("Error al abrir el fichero \n");
	}
		
	return 0;
}


/*Inserta un nodo al final de la lista */
void insertar (tNodo **lista, char car)
{
	tNodo *p1, *p2;

	p1 = *lista;
	
	/*Si es el primer elemento*/
	if(p1==NULL)
	{
		p1 = malloc(sizeof(tNodo));
		
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

		p2 = malloc(sizeof(tNodo));
		
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
void recorrer (tNodo *lista)
{
	char car;
	int nA,nE,nI,nO,nU;
	int numLineas = 1;
	int vocales[5];

	inicializar_vocales(vocales);
	printf("%i) ",numLineas);
	while(lista != NULL)
	{
		car = lista->car;

		if (car=='\n')
		{
			printf("%c", car);
			printf("num. a = : %i ", vocales[0]);
			printf("num. e = : %i ", vocales[1]);
			printf("num. i = : %i ", vocales[2]);
			printf("num. o = : %i ", vocales[3]);
			printf("num. u = : %i ", vocales[4]);

			inicializar_vocales(vocales);
			numLineas ++;
			
			/*Pintamos el indice de linea, excepto para la ultima*/
			if(lista->sig != NULL)
				printf("\n%i) ", numLineas);
				
		}else{
					
			printf("%c",car);
			switch (car){
			 case 'a':
			 		vocales[0]++;
			 		break;
			 case 'A':
			 		vocales[0]++;
			 		break;
			 case 'e': 
			 		vocales[1]++;
			 		break;
			  case 'E': 
			  		vocales[1]++;
			 		break;
			 case 'i': 
			 		vocales[2]++;
			 		break;
			 case 'I': 
			 		vocales[2]++;
			 		break;
			 case 'o': 
			 		vocales[3]++;
			 		break;
			 case 'O': 
			 		vocales[3]++;
			 		break;
			 case 'u': 
			 		vocales[4]++;
			 		break;
			 case 'U': 
					vocales[4]++;
			 }
		 }
		lista = lista->sig;
	}
}

/*Libera todos los nodos de la lista*/
void liberar(tNodo *lista)
{
	tNodo *pAux;
	
	while(lista != NULL)
	{
		pAux = lista;
		lista = lista->sig;
		free(pAux);
	}
	
}

/*Inicializa los valores del array que cuenta
  el numero de vocales*/
void inicializar_vocales(int vocales[])
{
	int i;
	
	for(i=0; i<5; i++)
	{
		vocales[i] = 0;	
	}
}
