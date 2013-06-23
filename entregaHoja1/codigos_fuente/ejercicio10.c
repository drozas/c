/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 10. Muestra cierta ejecucion por pantalla */

#include <stdio.h>

int main(void)
{
	int i,j,n;
	
	do
	{
		printf("Escribe un numero: ");
		scanf("%i", &n);
		if (n<=0)
		{
			printf("El numero debe ser al menos 1\n");
		}
	}while(n<=0);
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
		{		
			printf("%i \t",j);
		}
		printf("\n");
	}

	return 0;
}
