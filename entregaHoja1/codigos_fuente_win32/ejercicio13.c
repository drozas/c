/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 13. Determina si un numero es primo. */

#include <stdio.h>

int main(void)
{
	int encontrado = -1;
	int i, num;
	
	do
	{
		printf("Introduce un numero : ");
		scanf("%i",&num);
		if (num<=0)
		{
			printf("Tiene que ser un numero natural\n");
		}
	}	
	while(num<=0);
		
	/*Será primo si solo es divisible por 1 y por el mismo*/
	i = 2;
	/*Pararemos el bucle cuando lo hayamos encontrado, o cuando hayamos probado con todos*/
	while(encontrado<0 && i<num)
	{
		if (num%i==0)
		{
			encontrado = 1;
		}
		i++;
	}
		
	if (encontrado<0)
		printf("El numero %i es primo \n.", num);
	else
		printf("El numero %i no es primo \n", num);
	
	return 0;
}
