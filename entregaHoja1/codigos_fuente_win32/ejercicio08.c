/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 8. Cuenta la cantidad de numeros negativos introducidos*/

#include <stdio.h>

int main(void)
{
	int cont,num;
	cont=0;
	
	printf("--------------------------------------------------------\n");
	printf("Vamos a contar cuantos numeros negativos introduces...\n");
	printf("Para acabar, introduce 0\n");
	printf("---------------------------------------------------------\n\n");
	do
	{
		printf("Escribe un numero : ");
		scanf("%i",&num);
		if (num<0)
		{
			cont++;
		}
	}	
	while(num!=0);
		
	printf("\n Has escrito %i numeros negativos. \n", cont);
		
	return 0;
}
