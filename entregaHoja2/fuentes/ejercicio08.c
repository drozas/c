/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 8. Busca los puntos de silla de una matriz*/

#include <stdio.h>
#define N 4

struct tipoPosicion{
	int fila;
	int columna;
	};
typedef struct tipoPosicion tPosicion;

int main(void)
{
	int i, j, k, val_aux, alguno;
	int matriz[N][N];
	tPosicion min_fila[N]; /*Guarda las posiciones de los minimos de cada fila*/
	tPosicion max_columna[N]; /*Guarda las posiciones de los maximos de cada columna*/
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			printf("Introduce el valor [%i,%i]de la matriz : ", i,j);
			scanf("%i", &matriz[i][j]);
		}
	
	printf("\n\n");
	/*Pintamos la matriz*/
	for(i=0; i<N; i++)
	{
		printf("|");
		for(j=0; j<N; j++)
		{
			printf("  %2.i  ", matriz[i][j]);
		}
		printf("|\n");
	}
	
	/*Obtenemos un vector con las posiciones minimas de cada fila*/
	k = 0;
	for(i=0; i<N; i++)
	{
		val_aux = matriz[i][0];
		min_fila[k].columna = 0;
		min_fila[k].fila = i;
		for (j=0; j<N; j++)
		{
			if (matriz[i][j]<val_aux)
			{
				val_aux = matriz[i][j];
				min_fila[k].columna = j;
			}			
		}
		
		k++;
	}
	

	

	/*Obtenemos un vector con las posiciones maximas de cada columna*/
	k = 0;
	for(i=0; i<N; i++)
	{
		val_aux = matriz[0][i];
		max_columna[k].fila = 0;
		max_columna[k].columna = i;
		for(j=0; j<N; j++)
		{
			if(matriz[j][i]>val_aux)
			{
				val_aux = matriz[j][i];
				max_columna[k].fila = j;
			}
		}
		k++;
	}
	
	
	/*Por último, comparamos las posiciones obtenidas en ambos vectores*/
	alguno = -1;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if ((max_columna[i].fila==min_fila[j].fila)&&(max_columna[i].columna==min_fila[j].columna))
			{
				printf("\nHay un punto de silla en : [%i , %i] \n", max_columna[i].fila, max_columna[i].columna);
				alguno = 1;
			}
		}
	}
	
	if (alguno<0)
		printf("No hay puntos de silla\n");
	
	return 0;
}
