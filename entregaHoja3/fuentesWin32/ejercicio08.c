/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 8. Suma dos matrices de tamaño dinamico*/

#include <stdio.h>
#include <stdlib.h>

struct tipoNodo{
	int valor;
	struct tipoNodo *sig;
	};
typedef struct tipoNodo tNodo;
	
/*Cabeceras de funciones auxiliares*/
int leerValorPos();
void insertar (tNodo **mat, int val);
void recorrer (tNodo *mat, int nfil);
void sumarMatrices (tNodo *mat1, tNodo *mat2);
void liberar(tNodo *mat);

int main(void)
{

	int nfil1,nfil2,ncol1,ncol2;
	tNodo *m1,*m2;
	int i,j,valAux;
	
	m1 = NULL;
	m2 = NULL;
	
	/*Leemos los valores de filas y columnas*/
	printf("Numero de filas de la primera matriz? \n");
	nfil1 = leerValorPos();
	printf("Numero de columnas de la primera matriz? \n");
	ncol1 = leerValorPos();
	printf("Numero de filas de la segunda matriz? \n");
	nfil2 = leerValorPos();
	printf("Numero de columnas de la segunda matriz? \n");
	ncol2 = leerValorPos();

	/*Comprobamos que se puedan sumar*/
	if((nfil1==nfil2)&&(ncol1==ncol2))
	{
		/*Leemos los valores de las matrices*/
		for(i=0; i<nfil1; i++)
			for(j=0; j<ncol1;j++)
			{
				printf("Escriba el valor para la pos [%i,%i] de la matriz 1: ", i,j);
				scanf("%i", &valAux);
				insertar(&m1,valAux);
			}	

		for(i=0; i<nfil1; i++)
			for(j=0; j<ncol1;j++)
			{
				printf("Escriba el valor para la pos [%i,%i] de la matriz 2: ", i,j);
				scanf("%i", &valAux);
				insertar(&m2,valAux);
			}			
		
		/*Mostramos su contenido*/
		printf("\tMatriz 1 \n");			
		recorrer(m1,nfil1);
		printf("Matriz 2 \n");
		recorrer(m2,nfil1);
			
		/*Realizamos y mostramos la suma*/	
		sumarMatrices(m1,m2);
		printf("Matriz 1 + Matriz 2 \n");
		recorrer(m1,nfil1);
			
		/*Y por ultimo liberamos la memoria*/
		liberar(m1);
		liberar(m2);
		
	}else{
		printf("Las matrices tienen distintas dimensiones. No se pueden sumar\n");
	}

	return 0;
}

/* Funciones auxiliares 								*/
/********************************************************/

/*Devuelve un valor positivo para filas o columnas*/
int leerValorPos()
{
	int val;
	
	do
	{
		printf("Introduce un valor : ");
		scanf("%i", &val);
		
		if (val<=0)
			printf("Tiene que ser un valor positivo \n");
	
	}while(val<=0);

	return val;
}

/*Inserta un nodo al final de la lista */
void insertar (tNodo **mat, int valor)
{
	tNodo *p1, *p2;

	p1 = *mat;
	
	/*Si es el primer elemento*/
	if(p1==NULL)
	{
		p1 = malloc(sizeof(tNodo));
		
		if (p1 != NULL)
		{
			/*Guardamos info, y hacemos q ese nodo apunte a null*/
			p1->valor = valor;
			p1->sig = NULL;
			*mat = p1;
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
			p2->valor = valor;
			p2->sig = NULL;
			
			/*Y lo apuntamos desde el que anteriormente era el ultimo*/
			p1->sig = p2;
		}
	}
}
	
/*Recorre la matriz mostrando su contenido por la salida estandar*/
void recorrer (tNodo *mat, int nfil)
{
	int nfilAux = 1;
	printf("\t");
	while(mat != NULL)
	{
		printf(" %i ", mat->valor);
		if ((nfilAux % nfil)==0)
			printf("\n\t");
		
		nfilAux++;
		mat = mat->sig;
	}
}
	
/*Suma dos matrices. La suma se guarda en la primera de ellas*/
void sumarMatrices (tNodo *mat1, tNodo *mat2)
{
	while(mat1!=NULL)
	{
		mat1->valor += mat2->valor;
		mat1 = mat1->sig;
		mat2 = mat2->sig;
	}
}
	
/*Libera todos los nodos de la matriz*/
void liberar(tNodo *mat)
{
	tNodo *pAux;
	
	while(mat!= NULL)
	{
		pAux = mat;
		mat = mat->sig;
		free(pAux);
	}	
}
