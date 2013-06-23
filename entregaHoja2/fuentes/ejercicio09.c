/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 9. Calcula los puntos mas cercanos*/
/*PROBLEMA : problema con libreria math.h*/

#include <stdio.h>
#include <math.h>
#define N 4


/*Creamos una estructura de tipoPunto*/
struct tPunto{
	float x1;
	float x2;
};
typedef struct tPunto punto;

/*Declaracion de funciones auxiliares*/
float distanciaEuclidea(punto x, punto y);
	

int main(void)
{
	punto puntos[N];

	int i,j,p1,p2;
	float aux, actual;
	
	/*Leemos las coordenadas de los puntos que nos da el usuario*/
	for(i=0; i<N; i++)
	{
		printf("Introduce la coordenada x el %iº punto : ", i+1);
		scanf("%f", &puntos[i].x1);
		printf("Introduce la coordenada y el %iº punto : ", i+1);
		scanf("%f", &puntos[i].x2);
	}
	
	/*Mostramos la informacion */
	for(i=0; i<N; i++)
	{
		printf("Pto %i : (%.2f,%.2f)\n", i+1, puntos[i].x1, puntos[i].x2);
	}
	
	/*A continuacion calculamos las distancias euclídeas de todos con todos
	y nos guardaremos las referencias de la menor*/
	
	i = 0;
	j = 0;
	p1 = 0;
	p2 = 0;
	/*Inicializamos con el primer par de puntos*/
	actual = distanciaEuclidea(puntos[0],puntos[1]);
	aux = 0.0;
	
	while(i<N)
	{
		j = i + 1;
		while(j<N)
		{
			aux = distanciaEuclidea(puntos[i],puntos[j]);
			printf("Distancia entre  (%.2f , %.2f) con (%.2f , %.2f) = ", puntos[i].x1, puntos[i].x2, puntos[j].x1, puntos[j].x2);
			printf("%.2f\n", aux);
			if (aux<actual) 
			{
				actual = aux;
				p1 = i;
				p2 = j;
			}
			j++;
		}
		i++;
	}
	
	printf("\n-------------------------------------------------------------------------------\n");
	printf("Los puntos mas cercanos son (%.2f , %.2f) con (%.2f , %.2f)", puntos[p1].x1, puntos[p1].x2, puntos[p2].x1, puntos[p2].x2);
	printf("\n-------------------------------------------------------------------------------\n");
	
	return 0;
}

/*************************************************************/
/*                   Funciones auxiliares                    */
/*************************************************************/


float distanciaEuclidea(punto x, punto y)
{
	/*La distancia euclídea en R2 es:
	d((x1, x2),((y1,y2))=((x1-y1)^2+(x2-y2)^2)^1/2*/

	/*POR PROBLEMAS CON LIBRERIA math.h NO SE CALCULA CORRECTAMENTE.
	  EN REALIDAD EL RESULTADO CORRECTO SE CALCULA : 
	float res = sqrt(((x.x1 - y.x1)*(x.x1 - y.x1)) + ((x.x2 - y.x2)*(x.x2 - y.x2)));*/

	float res = ((x.x1 - y.x1)*(x.x1 - y.x1)) + ((x.x2 - y.x2)*(x.x2 - y.x2));
	return res;
}
