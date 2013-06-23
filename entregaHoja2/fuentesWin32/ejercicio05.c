/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 5. Define una estructura de datos fecha. 
                 Recibe dos fechas y las imprime en orden */

#include <stdio.h>

/*Definicion  y renombramiento de tipo fecha*/
struct tipoFecha{
	int dia,mes;
	unsigned anio;
	};
typedef struct tipoFecha tFecha;
	
int main(void)
{
	tFecha fecha1,fecha2;
	int fecha1mayor = 0;
	/*Pedimos dos fechas */
	do
	{
		printf("Introduzca el dia de la primera fecha : ");
		scanf("%i", &fecha1.dia);
	}while(fecha1.dia<1 || fecha1.dia>31);
	
	do
	{
		printf("Introduzca el mes de la primera fecha  :");
		scanf("%i", &fecha1.mes);
	}while(fecha1.mes<1 || fecha1.mes>12);
	
	printf("Introduzca el año de la primera fecha : ");
	scanf("%i", &fecha1.anio);
		
	
	do
	{
		printf("Introduzca el dia de la segunda fecha : ");
		scanf("%i", &fecha2.dia);
	}while(fecha2.dia<1 || fecha2.dia>31);
	
	do
	{
		printf("Introduzca el mes de la segunda fecha  :");
		scanf("%i", &fecha2.mes);
	}while(fecha2.mes<1 || fecha2.mes>12);
	
	printf("Introduzca el año de la segunda fecha : ");
	scanf("%i", &fecha2.anio);
	
	
	/*Y a continuacion procedemos a compararlas */
	
	if (fecha1.anio==fecha2.anio)
	{
		if(fecha1.mes==fecha2.mes)
		{
			if(fecha1.dia==fecha2.dia)
			{
				fecha1mayor=0;
			}else if(fecha1.dia>fecha2.dia){
				fecha1mayor=1;
			
			}else{
				fecha1mayor=-1;
			}
				
		}else if(fecha1.mes>fecha2.mes){
			fecha1mayor=1;
			
		}else{
			fecha1mayor=-1;
		}
		
	}else if(fecha1.anio>fecha2.anio){
		fecha1mayor=1;
		
	}else{
		fecha1mayor=-1;
	}		
	
	/*Y mostramos el resultado por pantalla*/
	switch(fecha1mayor){
		case 0 : 
			printf("¡Las dos fechas son iguales!\n");
			printf("\t%2i-%i-%i\n", fecha1.dia, fecha1.mes, fecha1.anio);
			printf("\t%2i-%i-%i\n", fecha2.dia, fecha2.mes, fecha2.anio);
			break;
		case 1 :
			printf("La fecha 1 es mayor :\n");
			printf("\t%2i-%i-%i\n", fecha1.dia, fecha1.mes, fecha1.anio);
			printf("\t%2i-%i-%i\n", fecha2.dia, fecha2.mes, fecha2.anio);
			break;
		case -1 :
			printf("La fecha 2 es mayor :\n");
			printf("\t%2i-%i-%i\n", fecha2.dia, fecha2.mes, fecha2.anio);
			printf("\t%2i-%i-%i\n", fecha1.dia, fecha1.mes, fecha1.anio);
	}
	return 0;
}
