/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 5. Convierte de segundos a horas-min-seg*/

#include <stdio.h>
#define HORA 3600
#define MINUTO 60

int main(void)
{
	int segundos, horas_res, min_res;
	
	do
	{
		printf("Escribe el valor de segundos que deseas convertir : ");
		scanf("%i", &segundos);
		if (segundos<=0)
		{
			printf("El numero de segundos introducidos debe ser al menos 1\n");
		}
	}while(segundos<=0);
	
	printf("%i segundos equivalen a : ", segundos);
	
	/*Vemos si "cabe", y si es asi dividimos, y seguimos trabajando con el modulo*/
	if(((segundos/HORA)>0))
	{
		horas_res= segundos/HORA;
		segundos= segundos%HORA;
	}
	
	if(((segundos/MINUTO)>0))
	{
		min_res= segundos/MINUTO;
		segundos= segundos%MINUTO;
	}
	
	printf("%i horas, %i minutos, %i segundos\n", horas_res, min_res, segundos);
	return 0;
	
}
