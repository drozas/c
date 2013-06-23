/*************************************************************
	}Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 17. Realiza un proceso secuencial con un numero natural*/

#include <stdio.h>

int main(void)
{
	int n, pasos;
	pasos=0;
	
	do
	{
		printf("Escribe un numero : ");
		scanf("%i", &n);
		if (n<1)
			printf("Error en el dato.\n");
	}while(n<1);

	printf("Valor inicial : %i \n", n);	
	
	while(n>1)
	{
			/*Si es par lo dividimos entre dos, si es impar lo multiplicamos 
			por tres y le sumamos 1*/
			if (n%2==0)
				n=n/2;
			else
				n=(n*3)+1;
		pasos++;
		printf("Siguiente valor : %i \n", n);
	}			
	
	printf("Valor final : %i ; Numero de pasos : %i \n", n, pasos);
	return 0;
}
