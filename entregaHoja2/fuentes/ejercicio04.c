/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 4. Calcula la suma de los elementos de una matriz
						 que no forman parte del diagonal*/

#include <stdio.h>
#define N 4

int main(void)
{
	int i, j,suma;
	int matriz[N][N];
	
	/*Pedimos los valores al usuario*/
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			printf("Introduce el valor matriz[%i][%i] :", i+1, j+1);
			scanf("%i", &matriz[i][j]);
		}
		
	/*Pintamos la matriz por pantalla, y calculamos la suma de elementos*/
	for(i=0, suma=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			printf("%5i", matriz[i][j]);
			if (j==(N-1))
				printf("\n");
			/*Sumamos todos los elementos menos los de la diagonal*/
			if (i!=j)
				suma  = suma + matriz[i][j];
		}
		
	printf("La suma de todos los elementos que no estan en la diagonal es : %i", suma);
		
	return 0;
}
