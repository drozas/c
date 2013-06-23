/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 15. Dibuja un triangulo isosceles. */

#include <stdio.h>

int main(void)
{
	int h, n, i, j;
	
	do
	{
		printf("Introduce la altura de la piramide : ");
		scanf("%i",&h);
		if (h<=0)
		{
			printf("Tiene que ser un numero natural\n");
		}
	}	
	while(h<=0);
		
	/*Tenemos que pintar h-n huecos, y n*2-1 asteriscos en cada vuelta*/
	for(n=1; n<=h; n++)
	{
		for (i=1; i<=(h-n);i++)
			printf("   ");
		
		for (i=1; i<=((n*2)-1); i++)
			printf("  *");
		
		printf("\n");
	}
	
	return 0;
}
