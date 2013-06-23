/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 12. Ordena un vector de enteros mediante
				 algoritmo de insercion directa*/

#include <stdio.h>
#define N 5

int main(void)
{
	int v[N];
	int i,j,aux;
	

	for(i=0; i<N; i++)
	{
		printf("Inserta un elemento : ");
		scanf("%i",&v[i]);
	}
	
	printf("Vector sin ordenar : \n [ ");
	for(i=0; i<N; i++)
		printf(" %i ", v[i]);
		
	printf("]\n");
	
	
	/*Cada elemento del vector se compara en cada iteracion con los que 
	le preceden, "hasta que encontramos su sitio"*/	
	for(i=1; i<N; i++)
	{
		aux = v[i];
		j = i - 1;
		/*Desplazamos todos los elementos mayores que v[i]*/
		while( (v[j]>aux) && (j>=0))
		{
			printf("Comparando %i con %i\n", v[j],aux);
			v[j+1] = v[j];
			j--;
		}
		
		/*Copiamos v[i] a su pos final*/
		v[j+1] = aux;
	}
		  
	
	printf("Vector ordenado : \n [ ");
	for(i=0; i<N; i++)
		printf(" %i ", v[i]);
		
	printf("]\n");
	
	return 0;
}
