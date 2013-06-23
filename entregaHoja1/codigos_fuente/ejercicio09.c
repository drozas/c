/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 9. Devuelve el menor, el mayor y la media
				 de los numeros introducidos por el usuario*/

#include <stdio.h>

int main(void)
{
	int nTotal, i, max, min;
	float media;
	int numeros[50];
	
	/*Primero pedimos al usuario cuantos va a introducir*/
	do
	{
		printf("¿Cuantos numeros quieres introducir? : ");
		scanf("%i",&nTotal);
		if (nTotal<=0)
		{
			printf("Tiene que ser un numero natural\n");
		}
	}	
	while(nTotal<=0);
		
	/*Guardamos las entradas en nuestro array*/
	for(i=0;i<nTotal;i++)
	{
		printf("Dame el %iº numero : ", i+1);
		scanf("%i", &numeros[i]);
	}
		
	/*A continuacion obtenemos los valores max, min y media*/
	media=0.0;
	max=numeros[0];
	min=numeros[0];
	for(i=0;i<nTotal;i++)
	{
		if (numeros[i]>max)
			max = numeros[i];
		
		if (numeros[i]<min)		
			min = numeros[i];
		
		media = media + numeros[i];		
	}
	
	media = media/nTotal;
	
	/*Por ultimo, mostramos la informacion */
	printf("*********************************************************\n");
	printf("Conjunto : "); 
	for(i=0;i<nTotal;i++)
		printf("%i , ",numeros[i]);
	printf("\nMaximo : %i\n",max);
	printf("Minimo : %i\n",min);
	printf("Media : %f\n",media);
	printf("*********************************************************\n");
	
	return 0;
}
