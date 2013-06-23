/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 10. Comprueba si un vector de enteros 
				 esta contenido en otro*/

#include <stdio.h>
#define N 4
#define M 5


struct tipoMarca{
	int data;
	int marcado;
	};
typedef struct tipoMarca tMarca;


int main(void)
{
	int v1[N];
	tMarca v2[M];
	int i, encontrado, j;
	
	/*Pedimos los valores al usuario, e inicializamos arrays*/
	for(i=0;i<N;i++)
	{
		printf("Introduce el valor v1[%i] : ", i+1);
		scanf("%i", &v1[i]);
	}
	for(i=0;i<M;i++)
	{
		printf("Introduce el valor v2[%i] : ", i+1);
		scanf("%i", &v2[i].data);
		v2[i].marcado = -1;
	}

	/*Recorremos el array origen comparando con el destino. Usamos marcas
	para el array destino para no falsear en caso de elementos repetidos :
	Ej.: [1,1,1] no esta contenido en [1,2,3,4]*/

	i=0;
	encontrado = 1;
	while ((i<N)&&(encontrado>0))
	{
		encontrado = -1;
		j = 0;
		while((j<M)&&(encontrado<0))
		{				
			if ( (v1[i]==v2[j].data)&&(v2[j].marcado<0) )
			{
				/*Marcamos y forzamos salida del bucle interno y 
				  permanencia en bucle externo*/
				v2[j].marcado = 1;
				encontrado = 1;
			}
			
			j++;
		}
		
		i++;
	}

	printf("\n----------------------------------------\n");
	
	if (encontrado>0)
		printf("El vector v1 esta contenido en v2\n");
	else
		printf("El vector 1 no esta contenido en v2\n");

	printf("----------------------------------------\n");
}
