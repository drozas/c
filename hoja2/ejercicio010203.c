/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/


#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	/*EJERCICIO 1*/
	/*float n1 = 10;
	float n2 = 5;
	float *p, *q;
	
	p = &n1;
	q = &n2;
	*q = *p + *q;
	printf("Valor de n1 : %f . Valor de n2 : %f ",n1,n2);*/
	/*El valor de n1 es 10, y el de n2 es 15*/
	/*Apuntamos a ambas variables. La ultima sentencia suma el valor apuntado
	por p (10) a n2. Seria equivalente a hacer n2=n1+n2*/
	
	
	/*EJERCICIO 2*/
/*	int x = 0;
	int *p1;
	int **p2;
*/	
	/*sentencia a*//*La asignacion del puntero es incompatible*/
	/*p1 = &p2;
	*p2 = &x;
	*p1 = 4;
	printf("Valor de x : %i", x);*/
	
	/*sentencia b*//*La asignacion del puntero es incompatible: crea un puntero hacia un entero sin conversion*/
	/*p2 = &x;
	*p2=4;
	printf("Valor de x : %i", x);*/
	
	//~ /*sentencia c*/
	//~ p2 = p1;/*asignacion a un tipo de puntero incompatible*/
	//~ p1 = &x;
	//~ *p2 = 4;/*crea un puntero hacia un entero sin conversion*/
	//~ printf("Valor de x : %i", x);
	
	//~ /*sentencia d*//*correcta*/
	//~ p2 = &p1;/*Apuntamos a la direccion de memoria del puntero p1*/
	//~ p1 = &x;/*Apuntamos a la direccion de memoria de x*/
	//~ **p2 = 4;/*Accedemos al valor, del valor del puntero*/
	//~ printf("Valor de x : %i", x);
	
	/*EJERCICIO 3*/
	int **p;
	int n, m , i;
	
	/*Pide al usuario un numero mayor que 0*/
	do
	{
		printf("Valor de n : \n");
		scanf("%d", &n);
	}while(n<=0);
	
	
	/*Reservamos memoria para n punteros a enteros*/
	p = (int**)malloc(n*sizeof(int*));
	
	/*Para cada puntero a entero*/
	for(i=0; i<n; i++)
	{
		/*Pedimos un numero de elementos*/
		int j;
		printf("Numero de elementos de la componente %d", i+1);
		scanf("%d", &m);
		
		/*Y reservamos memoria para m enteros*/
		p[i] = (int *)malloc(m*sizeof(int));
		/*Y a continuacion pedimos dichos valores*/
		for (j=0; j<m; j++)
			scanf("%d", &p[i][j]);
		
	}
	/*El objetivo del programa es crear una matriz dinamica de valores enteros,
	solicitando su tamaño y sus valores al usuario*/
	
	return 1;
}
